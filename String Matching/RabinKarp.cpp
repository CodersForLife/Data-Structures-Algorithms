#include <bits/stdc++.h>

using namespace std;

void RabinKarp(char pattern[], char text[])
{
    int d = 256;
    int q = 257;      // It can be any prime number only
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int PatternHashValue = 0;
    int TextHashValue = 0;
    int h = 1;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++)
    {
        PatternHashValue = (d * PatternHashValue + pattern[i]) % q;
        TextHashValue = (d * TextHashValue + text[i]) % q;
    }

    for (i = 0; i <= N - M; i++)
    {
        if ( PatternHashValue == TextHashValue )
        {
            for (j = 0; j < M; j++)
            {
                if (text[i+j] != pattern[j])
                    break;
            }

            if (j == M)
                cout<<"Index of Pattern in Text "<< i<<endl;
        }

        if ( i < N-M )
        {
            TextHashValue = (d*(TextHashValue - text[i]*h) + text[i+M])%q;

            if (TextHashValue < 0)
            TextHashValue = (TextHashValue + q);
        }
    }
}

int main()
{
    char text[] = "abaacabadaba";
    char pattern[] = "aba";
    RabinKarp(pattern, text);
    return 0;
}
