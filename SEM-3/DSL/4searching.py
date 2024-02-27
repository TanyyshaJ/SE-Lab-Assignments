class searching_ops:
    def __init__(self):
        self.roll_arr = []
        self.sorted_arr = []

    def input_random(self):
        num = int(input("Enter the number of students who attended the program: "))
        for i in range(num):
            self.roll_arr.append(int(input("Roll No.: ")))

        self.sorted_arr = sorted(self.roll_arr)
        return self.roll_arr
    
    def lin_search(self):
        find = int(input("Enter the Roll number to be searched: "))
        found = False
        for roll in  self.roll_arr:
            if roll == find:
                found = True
                break

        if found:
            print(f"Roll number {find} attended the training program")
                
        else:
            print(f"Roll number {find} did not attend the training program")
                

    def sentinel_search(self):
        find = int(input("Enter the Roll number to be searched: "))
        n = len(self.roll_arr)
        last_elem = self.roll_arr[n-1]
        self.roll_arr[n-1] = find
        ind = 0
        while(self.roll_arr[ind] != find):
            ind+=1

        self.roll_arr[n-1] = last_elem

        if ind<n-1 or self.roll_arr[n-1]==find:
            print(f"Roll number {find} attended the program")
        else:
            print(f"Roll number {find} did not attend the program")

    def bin_search(self, target):
        n = len(self.roll_arr)
        sorted_arr = self.sorted_arr
        start = 0 
        end = n - 1
    
        target = target

        while start<=end:
            mid = start + (end-start)//2

            if sorted_arr[mid] == target:
                return mid
            
            elif sorted_arr[mid] < target:
                start = mid+1
            
            else:
                end = mid - 1

        return -1
        
    def fibo_search(self, target):
        target = target
        sorted_arr = self.sorted_arr

        fibM2 = 0
        fibM1 = 1
        fib = fibM1 + fibM2

        while(fib<len(sorted_arr)):
            fibM2 = fibM1
            fibM1 = fib
            fib = fibM1 + fibM2

        offset = -1

        while fib > 1:
            i = min(offset + fibM2, len(sorted_arr)-1)

            if sorted_arr[i]<target:
                fib = fibM1
                fibM1 = fibM2
                fibM2 = fib - fibM1
                offset = i

            elif sorted_arr[i]>target:
                fib = fibM2
                fibM1 = fibM1 - fibM2
                fibM2 = fib - fibM1
            
            else:
                return i
            
        if fibM1 and sorted_arr[offset + 1] == target:
            return offset+1
        
        return -1

obj = searching_ops()
obj.input_random()

flag = True

while(flag):

    print("------MENU------")
    print("1. Linear Search")
    print("2. Sentinel Search")
    print("3. Binary Search")
    print("4. Fibonacci Search")
    print("5. EXIT")
    op = int(input("Enter an option: "))

    if op==1:
        obj.lin_search()

    elif op==2:
        obj.sentinel_search()

    elif op==3:
        target = int(input("Enter Roll number to be searched: "))
        result = obj.bin_search(target)
        if result!=-1:
            print(f"{target} attended the program and is at index {result}")
        else:
            print(f"{target} did not attend the program")

    elif op==4:
        target = int(input("Enter Roll number to be searched: "))
        result = obj.fibo_search(target)
        if result!=-1:
            print(f"{target} attended the program and is at index {result}")
        else:
            print(f"{target} did not attend the program")

    elif op==5:
        flag = False
        break