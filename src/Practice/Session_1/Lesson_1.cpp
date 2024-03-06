// kiểm tra và phân tích dữ liệu log cuộc gọi thoại
#include <iostream>
#include <string>
#include <regex>
#include <unordered_map>
using namespace std;

int convertTime(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    int second = stoi(time.substr(6, 2));

    return hour * 3600 + minute * 60 + second;
}

bool isValidPhone(const string& phone) {
    regex phonePattern(R"(^0\d{9}$)");
    return regex_match(phone, phonePattern);
}

void data_process(bool &checkPhone, long &totalCalls, unordered_map<string, long> &numberCallsFrom, unordered_map<string, long> &totalTimeCallsFrom) {
    string call, fromNumber, toNumber, date, fromTime, endTime;
    // int time = convertTime(endTime) - convertTime(fromTime);
    while(true) {
        cin >> call;
        if(call == "#") break;
        else {
            cin >> fromNumber >> toNumber >> date >> fromTime >> endTime;
            
            totalCalls++;
            numberCallsFrom[fromNumber]++;
            totalTimeCallsFrom[fromNumber] += convertTime(endTime) - convertTime(fromTime);            
            if(checkPhone) 
                checkPhone = isValidPhone(fromNumber) && isValidPhone(toNumber);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    bool checkPhone = true;
    long totalCalls = 0;
    unordered_map<string, long> numberCallsFrom;
    unordered_map<string, long> totalTimeCallsFrom;

    data_process(checkPhone, totalCalls, numberCallsFrom, totalTimeCallsFrom);

    string query;
    string phone;
    while(true) {
        cin >> query;
        if(query == "#") break;
        else if(query.length() == 18) {
            cin >> phone;
            cout << numberCallsFrom[phone] << '\n';
        } else if(query.length() == 19 && query[1] == 'n')
            cout << totalCalls << '\n';
        else if(query.length() == 22) {
            cin >> phone;
            cout << totalTimeCallsFrom[phone] << '\n';
        } else if(query.length() == 19 && query[1] == 'c')
            cout << checkPhone << '\n';
    }

    return 0;
}
// Dxy