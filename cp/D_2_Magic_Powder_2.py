def can_bake_cookies(cur, ingredients, available, k):
    for i in range(len(ingredients)):
        needed = (ingredients[i] * cur) - available[i]
        if needed > 0:
            k -= needed
        if k < 0:
            return False
    return k >= 0

def main():
    n, k = map(int, input().split())
    ingredients = list(map(int, input().split()))
    available = list(map(int, input().split()))

    low, high = 0, 10**18
    ans = 0

    while low <= high:
        mid = low + (high - low) // 2

        if can_bake_cookies(mid, ingredients, available, k):
            low = mid + 1
            ans = mid
        else:
            high = mid - 1

    print(ans)

if __name__ == "__main__":
    main()
