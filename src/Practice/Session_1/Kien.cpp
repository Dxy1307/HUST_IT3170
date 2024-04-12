#include <bits/stdc++.h>

using namespace std;
set < int > S;
pair < int, int > temp[1009];
int a[1009][1009], h[1009][1009];
int n, m, res, l, r;

int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            cin >> a[i][j];
            h[i][j] = 0;
            if(a[i][j] == 1)
                h[i][j] = h[i -1][j] + 1;
        }

    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
            temp[j] = {h[i][j], j};

        sort(temp +1, temp + m + 1);
        S.clear();
        S.insert(n +1);
        S.insert(0);

        for(int j=1; j<=m; ++j)
        {
            auto it = S.lower_bound(temp[j].second);
            r = *it;
            it--;
            l = *it;

            res = max(res, (r - l - 1) * temp[j].first);
            S.insert(temp[j].second);
        }
    }

    cout << res;
    return 0;
}