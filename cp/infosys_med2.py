def count_KModulo_numbers_optimized(N, K):
    count = 0
    
    for num in range(K, N+1, K):
        current_num = num
        even_count = 0
        odd_count = 0
        
        while current_num > 0:
            digit = current_num % 10
            if digit % 2 == 0:
                even_count += 1
            else:
                odd_count += 1
            current_num //= 10
        
        if even_count == odd_count:
            count += 1
    
    return count


def count_KModulo_numbers_final_optimized(N, K):
    count = 0
    
    # Iterate through even lengths in the range [2, 8]
    for num_digits in range(2, 9, 2):
        start_range = 10**(num_digits - 1)
        end_range = min(10**num_digits, N + 1)
        
        # Start with the smallest multiple of K within the current range
        start_num = start_range + (K - (start_range % K)) % K
        
        # Iterate through numbers with even length and divisible by K
        for num in range(start_num, end_range, K):
            current_num = num
            even_count = 0
            odd_count = 0
            
            while current_num > 0:
                digit = current_num % 10
                if digit % 2 == 0:
                    even_count += 1
                else:
                    odd_count += 1
                current_num //= 10
            
            if even_count == odd_count:
                count += 1
    
    return count

if __name__=="__main__":
    tt = int(input())
    for _ in range(tt):
        N, K = map(int, input().split())
        result = count_KModulo_numbers_final_optimized(N, K)
        print(result)
