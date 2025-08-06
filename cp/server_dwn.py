

def solution(availability, reliability):
    pairs = zip(availability, reliability)
    pairs = sorted(pairs, reverse=True)
    output = 0
    reliability_sum = 0
    for a, r in pairs:
        reliability_sum += r
        output = max(output, reliability_sum * a)
    return output % (10 ** 9 + 7)


if __name__ == "__main__":
    n = int(input())
    requests = list(map(int, input().split()))
    m = int(input())
    health = list(map(int, input().split()))
    k = int(input())

    print(solution(requests, health))