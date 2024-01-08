#NAME: JACINTO QUIMUA
#Date: January 2024

'''
In this file I implement my abcd sorting algorithm
'''

import math

'''
  Returns the sequence that n+G(n) belongs to. 
  For example, n=13 implies c-sequence, because n+G(n) = 13+11 = 24, and 24 is part of the c-sequence
'''
def get_sequence(n):
    #checking a-sequence
    if((n-2)%4==0):
        return "a"
    elif((n-3)%4==0):
        return "a"

    #checking b-sequence
    elif((n-9)%16==0):
        return "b"
    elif((n-12)%16==0):
        return "b"

    #checking c-sequence
    elif((n-8)%16==0):
        return "c"
    elif((n-13)%16==0):
        return "c"

    #checking d-sequence
    elif(n%8==0 and (n/8)%2==0):
        return "d"
    elif((n+4)%8==0 and ((n+4)/8)%2!=0):
        return "d"
    elif((n-1)%8==0 and ((n-1)/8)%2==0):
        return "d"
    elif((n+3)%8==0 and ((n+3)/8)%2!=0):
        return "d"

    return "N/A"


'''
  Returns the index of the sequence term. 
  For example, the general term of the a-sequence is a(k), so the function returns k
'''
def get_sequence_index(n):
    #checking a-sequence
    if((n-2)%4==0):
        return (n-2)/4
    elif((n-3)%4==0):
        return (n-3)/4

    #checking b-sequence
    elif((n-9)%16==0):
        return (n-9)/16
    elif((n-12)%16==0):
        return (n-12)/16

    #checking c-sequence
    elif((n-8)%16==0):
        return (n-8)/16
    elif((n-13)%16==0):
        return (n-13)/16

    #checking d-sequence
    elif(n%8==0 and (n/8)%2==0):
        return n/8
    elif((n+4)%8==0 and ((n+4)/8)%2!=0):
        return (n+4)/8
    elif((n-1)%8==0 and ((n-1)/8)%2==0):
        return (n-1)/8
    elif((n+3)%8==0 and ((n+3)/8)%2!=0):
        return (n+3)/8

    return -1


'''
  Returns 0 if the kth term of a sequence is the first one, and 1 otherwise.
  For example the a-sequence has 5 and 5 as its first term, a(0), k=0.
  The point is that it allows us to know if when n=2, for example, which has G(n)=3, which 5 in the a-sequence
  their sum (n+G(n)) refers to. In this case it refers to the first 5, and the second is for when n=3.
'''
def get_0th_or_1st(n):
    #checking a-sequence
    if((n-2)%4==0):
        return 0
    elif((n-3)%4==0):
        return 1

    #checking b-sequence
    elif((n-9)%16==0):
        return 0
    elif((n-12)%16==0):
        return 1

    #checking c-sequence
    elif((n-8)%16==0):
        return 0
    elif((n-13)%16==0):
        return 1

    #checking d-sequence
    elif(n%8==0 and (n/8)%2==0):
        return 0
    elif((n+4)%8==0 and ((n+4)/8)%2!=0):
        return 0
    elif((n-1)%8==0 and ((n-1)/8)%2==0):
        return 1
    elif((n+3)%8==0 and ((n+3)/8)%2!=0):
        return 1

    return -1


'''
  Returns the cycle of n, which is defined as applying g(n) repeatedly till the result is n again.
'''
def C(n):
    if n <= 1:
        return 1
    else:
        return pow(2, math.floor(math.log2(math.log2(n)))+1)

'''
  Returns the frequency of a sequence term
  IMPORTANT: This function is only applicable for sequences in
              intervals where log2cycle > 2 aka l>2
'''
def get_frequency( l,  sequence,  index):
    if(l == 2):
        return 1
    elif(l > 2):
        index_const_part = pow(2, pow(2, l-1)-4)-1
        #checking a-sequence
        if(sequence == "a"):
            #first a
            if(index%4==0):
                return (index/4)-index_const_part
            #second a
            elif((index-1)%4==0):
                return ((index-1)/4)-index_const_part
            #third a
            elif((index-2)%4==0):
                return ((index-2)/4)-index_const_part
            #fourth a
            elif((index-3)%4==0):
                return ((index-3)/4)-index_const_part

        #checking b-sequence
        if(sequence == "b"):
            return index - index_const_part

        #checking c-sequence
        if(sequence == "c"):
            return index - index_const_part

        #checking d-sequence
        if(sequence == "d"):
            #first d
            if(index%2==0):
                return (index/2)-index_const_part
            #second d
            elif((index-1)%2==0):
                return ((index-1)/2)-index_const_part

    return -1


'''
  Returns the index of a sequence term in the dacbabca pattern, if l=2 and dadacbabca pattern, if l>2
'''
def get_pattern_index( l,  sequence,  index,  is0thor1st = 0):
    #checking a-sequence
    if(sequence == "a"):
        if(l == 2):
            if(index == 1):
                return 1
            elif(index == 2):
                return 4
        if(l>2):
            if(index%4==0):
                return 1
            elif(index%2==0 and index%4!=0):
                return 6
            elif((index-1)%4==0):
                return 3
            elif((index-3)%4==0):
                return 9
    
    #checking b-sequence
    if(sequence == "b"):
        if(l == 2):
            if(is0thor1st == 0):
                return 3
            elif(is0thor1st == 1):
                return 5
        if(l > 2):
            if(is0thor1st == 0):
                return 5
            elif(is0thor1st == 1):
                return 7

    #checking c-sequence
    if(sequence == "c"):
        if(l == 2):
            if(is0thor1st == 0):
                return 2
            elif(is0thor1st == 1):
                return 6
        if(l > 2):
            if(is0thor1st == 0):
                return 4
            elif(is0thor1st == 1):
                return 8
      
    #checking d-sequence
    if(sequence == "d"):
        if(l == 2):
            if(index == 1):
                return 0
        if(l > 2):
            if(index%2 == 0):
                return 0
            else:
                return 2

    return -1


'''
    Sorts a list of integers using the abcd sort
'''
def abcd_sort(array_to_sort):
    N = len(array_to_sort)
    sorted_array = []
    D = {}
    max_l = 0
    max_frequency = 0
    #STEP 1
    for i in range(0, N):
        l = int(math.log2(C(array_to_sort[i])))
        if l > max_l:
            max_l = l
        if l not in D:
            D[l] = []
            D[l].append(array_to_sort[i])
        else:
            D[l].append(array_to_sort[i])
    #STEP 2
    for l in D:
        sequence_dict = {}
        for number in D[l]:
            sequence = get_sequence(number)
            if sequence not in sequence_dict:
                sequence_dict[sequence] = []
                sequence_dict[sequence].append(number)
            else:
                sequence_dict[sequence].append(number)
        D[l] = sequence_dict
    #STEP 3
    for l in D:
        for sequence in D[l]:
            sequence_index_dict = {}
            for number in D[l][sequence]:
                index = int(get_sequence_index(number))
                if index not in sequence_index_dict:
                    sequence_index_dict[index] = []
                    sequence_index_dict[index].append(number)
                else:
                    sequence_index_dict[index].append(number)
            D[l][sequence] = sequence_index_dict
    #STEP 4
    for l in D:
        for sequence in D[l]:
            for index in D[l][sequence]:
                is0th_dict = {0: []}
                is1st_dict = {1: []}
                for number in D[l][sequence][index]:
                    is0thor1st = get_0th_or_1st(number)
                    if is0thor1st == 0:
                        is0th_dict[0].append(number)
                    elif is0thor1st == 1:
                        is1st_dict[1].append(number)
                D[l][sequence][index] = {}
                D[l][sequence][index].update(is0th_dict)
                D[l][sequence][index].update(is1st_dict)
    #STEP 5
    for l in D:
        for sequence in D[l]:
            if sequence == "a" or sequence == "d":
                for index in D[l][sequence]:
                    if 0 in D[l][sequence][index]:
                        all0th_array = D[l][sequence][index][0]
                    else:
                        all0th_array = []
                    if 1 in D[l][sequence][index]:
                        all1st_array = D[l][sequence][index][1]
                    else:
                        all1st_array = []
                    all0th_array.extend(all1st_array) #UPDATE PSEUDO-CODE
                    if l > 1:
                        D[l][sequence][index] = all0th_array
                    elif l <= 1:
                        D[l] = all0th_array
    #STEP 6
    for l in D:
        if l > 1:
            frequency_dict = {}
            for sequence in D[l]:
                for index in D[l][sequence]:
                    frequency = int(get_frequency(l, sequence, index))
                    if frequency > max_frequency:
                        max_frequency = frequency
                    if frequency not in frequency_dict:
                        frequency_dict[frequency] = {}
                        if sequence not in frequency_dict[frequency]:
                            frequency_dict[frequency][sequence] = {}
                        if isinstance(D[l][sequence][index], list):
                            frequency_dict[frequency][sequence][index] = []
                            frequency_dict[frequency][sequence][index].extend(D[l][sequence][index])
                        elif isinstance(D[l][sequence][index], dict):
                            if index not in frequency_dict[frequency][sequence]:
                                frequency_dict[frequency][sequence][index] = {}
                            for is0thor1st in D[l][sequence][index]:
                                if is0thor1st not in frequency_dict[frequency][sequence][index]:
                                    frequency_dict[frequency][sequence][index][is0thor1st] = []
                                    frequency_dict[frequency][sequence][index][is0thor1st].extend(D[l][sequence][index][is0thor1st])
                                else:
                                    frequency_dict[frequency][sequence][index][is0thor1st].extend(D[l][sequence][index][is0thor1st])
                    else:
                        if sequence not in frequency_dict[frequency]:
                            frequency_dict[frequency][sequence] = {}
                        if isinstance(D[l][sequence][index], list):
                            frequency_dict[frequency][sequence][index] = []
                            frequency_dict[frequency][sequence][index].extend(D[l][sequence][index])
                        elif isinstance(D[l][sequence][index], dict):
                            if index not in frequency_dict[frequency][sequence]:
                                frequency_dict[frequency][sequence][index] = {}
                            for is0thor1st in D[l][sequence][index]:
                                if is0thor1st not in frequency_dict[frequency][sequence][index]:
                                    frequency_dict[frequency][sequence][index][is0thor1st] = []
                                    frequency_dict[frequency][sequence][index][is0thor1st].extend(D[l][sequence][index][is0thor1st])
                                else:
                                    frequency_dict[frequency][sequence][index][is0thor1st].extend(D[l][sequence][index][is0thor1st])
            D[l] = frequency_dict
    #STEP 7
    for l in D:
        if l > 1:
            for frequency in D[l]:
                pattern_index_dict = {}
                for sequence in D[l][frequency]:
                    for index in D[l][frequency][sequence]:
                        if sequence == "b" or sequence == "c":
                            for is0thor1st in D[l][frequency][sequence][index]:
                                pattern_index = int(get_pattern_index(l, sequence, index, is0thor1st))
                                if pattern_index not in pattern_index_dict:
                                    pattern_index_dict[pattern_index] = []
                                    pattern_index_dict[pattern_index].extend(D[l][frequency][sequence][index][is0thor1st])
                                else:
                                    pattern_index_dict[pattern_index].extend(D[l][frequency][sequence][index][is0thor1st])
                        else:      
                            pattern_index = int(get_pattern_index(l, sequence, index))
                            if pattern_index not in pattern_index_dict:
                                pattern_index_dict[pattern_index] = []
                                pattern_index_dict[pattern_index].extend(D[l][frequency][sequence][index])
                            else:
                                pattern_index_dict[pattern_index].extend(D[l][frequency][sequence][index])
                D[l][frequency] = pattern_index_dict
    #STEP 8
    for l in D:
        if l > 1:
            for frequency in D[l]:
                frequency_array = []
                for pattern_index in range(0, 10):
                    if pattern_index in D[l][frequency]:
                        frequency_array.extend(D[l][frequency][pattern_index])
                D[l][frequency] = frequency_array
    #STEP 9
    for l in D:
        if l > 1:
            l_array = []
            for frequency in range(1, max_frequency+1):
                if frequency in D[l]:
                    l_array.extend(D[l][frequency])
            D[l] = l_array
    #STEP 10
    for l in range(0, max_l+1):
        if l in D:
            sorted_array.extend(D[l])
    
    return sorted_array