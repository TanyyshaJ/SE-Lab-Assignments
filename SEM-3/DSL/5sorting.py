class sort_ops:
    def __init__(self):
        self.sort_list = []
    
    def input_list(self):
        self.sort_list = input("Enter a list of numbers separated by space: ")
        self.sort_list = list(map(int, self.sort_list.split()))

    def selection_sort(self):
        for i in range(len(self.sort_list)-1):
            min_val = self.sort_list[i]
            for j in range(i+1, len(self.sort_list)):
                if self.sort_list[j] < min_val:
                    self.sort_list[j], min_val = min_val, self.sort_list[j]
                self.sort_list[i] = min_val
            
        return self.sort_list
    
    def bubble_sort(self):
        n = len(self.sort_list)
        for i in range(n-1):
            for j in range(0, n-i-1):
                if self.sort_list[j] > self.sort_list[j+1]:
                    self.sort_list[j], self.sort_list[j+1] = self.sort_list[j+1], self.sort_list[j]

        return self.sort_list

    def insertion_sort(self):
        for i in range(1, len(self.sort_list)):
            current = self.sort_list[i]
            j = i - 1
            while j >= 0 and self.sort_list[j] > current:
                self.sort_list[j+1] = self.sort_list[j]
                j -= 1
            self.sort_list[j+1] = current

        return self.sort_list

    def shell_sort(self):
        n = len(self.sort_list)
        gap = n // 2
        while gap > 0:
            for i in range(gap, n):
                temp = self.sort_list[i]
                j = i
                while j >= gap and self.sort_list[j - gap] > temp:
                    self.sort_list[j] = self.sort_list[j - gap]
                    j -= gap
                self.sort_list[j] = temp
            gap //= 2

        return self.sort_list


obj = sort_ops()
flag = True

while flag:
    print("------MENU------")
    print("1. Input List")
    print("2. Selection Sort")
    print("3. Bubble Sort")
    print("4. Insertion Sort")
    print("5. Shell Sort")
    print("6. EXIT")
    op = int(input("Enter an option: "))

    if op == 1:
        obj.input_list()
        print("List Entered!")

    elif op == 2:
        result = obj.selection_sort()
        print("Selection Sorted List:", result)

    elif op == 3:
        result = obj.bubble_sort()
        print("Bubble Sorted List:", result)

    elif op == 4:
        result = obj.insertion_sort()
        print("Insertion Sorted List:", result)

    elif op == 5:
        result = obj.shell_sort()
        print("Shell Sorted List:", result)

    elif op == 6:
        flag = False
        print("Exiting the Program")

    
 