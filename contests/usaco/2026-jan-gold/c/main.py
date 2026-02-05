MOD = int(1e9) + 7
TODO = 0
from math import inf


def stress(d, arr):
    # coordinate compression
    cps = set()
    for p, t in arr:
        cps.add(p)
        if p - d >= 0:
            cps.add(p - d)
        cps.add(p + d)
    cps = list(sorted(cps))
    m = dict()
    for i, x in enumerate(cps):
        m[x] = i

    MAX = cps[-1] + 1

    camps = set()
    coaches = set()
    for p, t in arr:
        if t == 0:
            camps.add(m[p])
        else:
            coaches.add(m[p])
    coaches_l = list(sorted(coaches))

    pref_camp = [0] * (MAX + 1)
    pref_coach = [0] * (MAX + 1)

    for i in range(MAX):
        pref_camp[i + 1] = pref_camp[i] + (i in camps)
        pref_coach[i + 1] = pref_coach[i] + (i in coaches)

    nco = len(coaches)

    dp = [1] * nco
    for i in range(nco):
        coach_i = coaches_l[i]
        j = pref_camp[coach_i + d + 1] - pref_camp[coach_i]
        if i == 0:
            dp[i] = 2**j + 1
        else:
            prev_coach = coaches_l[i - 1]
            o = pref_camp[prev_coach + d + 1] - pref_camp[coach_i]
            dp[i] = dp[i - 1] + dp[i - 1] * (2 ** (j - o))

        # TODO: figure out which non overlap
        k = i - 2
        while k >= 0 and coaches_l[k] + d >= coach_i:
            k -= 1
        if k >= 0:
            # dp[i] += dp[k] * (2 ** j)
            pass
        else:
            pass
    if len(dp) == 0:
        return 0
    return dp[-1] % MOD - 1


def solve(d, arr):
    pass


def main():
    N, d = [int(x) for x in input().split(" ")]
    arr = []
    for _ in range(N):
        p, o = [int(x) for x in input().split(" ")]
        arr.append((p, o))
    print(stress(d, arr))


if __name__ == "__main__":
    main()
