def myfunc():
    lookfor=.3
    denominator=10
    founded=False
    while(True):
        pivot=1/denominator
        print("denominator: ")
        print(denominator)
        print("pivot: ")
        print(pivot)
        i=0
        while(i<1):
            print(i)
            if(lookfor==i):
                founded=True
                break
            i+=pivot
        if(founded):
            break
        denominator*=10
        
myfunc()