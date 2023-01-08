#include <atomic>
#include <string.h>

#include "dynamic_programming.h"

char* dynamic_programming::longest_common_substring(char* str1, char* str2)
{
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);

    int* dp = (int*)malloc((str2_len + 1) * sizeof(int));
    memset(dp, 0, str2_len);

    int max_len = 0;
    int max_idx = 0;

    for (int i = 1; i <= str1_len; i++)
    {
        for (int j = str2_len; j >= 1; j--)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[j] = dp[j - 1] + 1;

                if (max_len < dp[j])
                {
                    max_len = dp[j];
                    max_idx = i;
                }
            }
            else
            {
                dp[j] = 0;
            }
        }
    }

    str1[max_idx] = '\0';

    free(dp);

    return str1 + max_idx - max_len;
}
