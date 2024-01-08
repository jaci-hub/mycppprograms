from abcd_sort import abcd_sort

if __name__ == '__main__':
    array_to_sort = [1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0]
    
    sorted_array = abcd_sort(array_to_sort)
    
    print('** BEFORE SORT **')
    print(array_to_sort)
    print('** AFTER SORT **')
    print(sorted_array)