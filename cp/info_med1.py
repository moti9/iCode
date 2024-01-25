def count_KModulo_numbers(N, K):
    count = 0
    
    for num in range(1, N+1):
        if num % K == 0:
            even_count = 0
            odd_count = 0
            for digit in str(num):
                if int(digit) % 2 == 0:
                    even_count += 1
                else:
                    odd_count += 1
            
            if even_count == odd_count:
                count += 1
    
    return count


if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        N, K = map(int, input().split())
        result = count_KModulo_numbers(N, K)
        print(result)
