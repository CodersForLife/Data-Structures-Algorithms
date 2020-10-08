def numsDivBy235(N):
    # assert: N>0 is established

    dp = [0]*N
    i_2 = i_3 = i_5 = 0
    dp[0] = 1

    # assert: dp[0..p-1] has the p numbers which are divisible by no prime other than 2,3,5

    # INV: (i_2, i_3, i_5 are cursors to the powers of 2, 3, 5 last used) and
    # (dp[i] stores the minimum number obtained by incrementing the power of 2,3,5 by 1 in previous numbers of the array)

    for p in range(1, N):
        dp[p] = min(dp[i_2]*2, dp[i_3]*3, dp[i_5]*5)
        if(dp[p] == dp[i_2] * 2):
            i_2 += 1
        if(dp[p] == dp[i_3] * 3):
            i_3 += 1
        if(dp[p] == dp[i_5] * 5):
            i_5 += 1

    # dp[1..N] is an array containing N numbers divisible by no prime other than 2,3,5
    return dp
