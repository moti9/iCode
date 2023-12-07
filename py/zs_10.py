import collections

def is_ascii(s):
    return all(ord(c) < 128 for c in s)

def bigram_frequencies(input_str):
    bigrams = [input_str[i:i+2] for i in range(len(input_str)-1)]
    return dict(collections.Counter(bigrams))

def feature_vector(input_str):
    freq_dict = bigram_frequencies(input_str)
    
    # Handle non-ASCII characters
    if not is_ascii(input_str):
        input_str = input_str.encode('utf-8').decode('utf-16')

    feature_vector_dict = {}
    for bigram, count in freq_dict.items():
        utf8_hex = ''.join(format(ord(char), 'x') for char in bigram.encode('utf-8'))
        decimal_index = int(utf8_hex, 16)
        feature_vector_dict[decimal_index] = count

    sorted_feature_vector = sorted(feature_vector_dict.items())

    return ' '.join([f"{index}:{count}" for index, count in sorted_feature_vector])

# Test cases
print(feature_vector("banana"))  # Output: "24942:2 25185:1 28257:2"
print(feature_vector("do or do not"))  # Output: "8292:1 8302:1 8303:1 25711:2 28271:1 28448:2 28530:1 28532:1 29216:1"