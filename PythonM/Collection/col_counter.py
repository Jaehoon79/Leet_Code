from collections import Counter

def main():
    #convert occurrences in a list
    list_data = ['apple', 'banana', 'orange', 'apple', 'mango', 'banana']
    list_cnt = Counter(list_data)
    print(list_cnt, type(list_cnt))
    #checking element in exist
    print('apple' in list_cnt)

    #Count characters in a string
    str_data = 'HooN NooH'
    str_cnt = Counter(str_data)
    print(str_cnt, type(str_cnt))
    #Access specific counts
    print(str_cnt['H'])
    
    #Finding Most Common Character
    mc_str_cnt = str_cnt.most_common(1)
    print(mc_str_cnt, type(mc_str_cnt))
    
    #updating Count and re-check most common Characters
    str_cnt['H'] += 10 # the count of 'H' become 12.
    mc_str_cnt = str_cnt.most_common(1)
    print(f"re-checking most common counter {mc_str_cnt}")

if __name__ == "__main__":
    main()

