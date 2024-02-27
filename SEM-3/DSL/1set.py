class StudentActivites:
    def __init__(self):
        self.uni_list = []
        self.cric_list = []
        self.bad_list = []
        self.foot_list = []

    def input_students(self):
        num_students = int(input("Enter the no. of students: "))
        for i in range(num_students):
            roll_num = int(input("Roll Number: "))
            self.uni_list.append(roll_num)

        print("List of roll numbers: ", self.uni_list)

    def input_activity_selection(self, activity_list, activity_name):
        num_activity_students = int(input(f"Enter number of students who play {activity_name}"))
        for i in range(num_activity_students):
            roll_num = int(input(f"Roll Number: "))
            activity_list.append(roll_num)
        
        print(f"List of all roll numbers who play {activity_name} is: ",activity_list)

    def intersection(self, list1, list2):
        return list(set(list1) & set(list2))
    
    def union(self, list1, list2):
        return list(set(list1) | set(list2))
    
    def difference(self, list1, list2):
        return list(set(list1) - set(list2))

    def symmetric_difference(self, list1, list2):
        return list(set(list1) ^ set(list2))
    
obj = StudentActivites()
obj.input_students()
flag = 1
obj.input_activity_selection(obj.cric_list, "cricket")
obj.input_activity_selection(obj.bad_list, "badminton")
obj.input_activity_selection(obj.foot_list, "football")
while(flag):

    print("------MENU-----")
    print("a. List of students who play both cricket and badminton")
    print("b. List of students who play either cricket or badminton but not both")
    print("c. Number of students who play neither cricket nor badminton")
    print("d. Number of students who play cricket and football but not badminton")
    op = input("Enter a choice: ")

    if op == 'a':
        cric_bad = obj.intersection(obj.cric_list, obj.bad_list)
        print("List of students who play both cricket and badminton: ", cric_bad)

    if op == 'b':
        cric_or_bad = obj.union(obj.cric_list, obj.bad_list)
        print("List of students who play both cricket and badminton: ", cric_or_bad)

    if op == 'c':
        cric_bad = obj.union(obj.cric_list, obj.bad_list)
        ans = len(obj.uni_list) - len(cric_bad)
        print("Number of students who play neither cricket nor badminton: ", ans)

    if op == 'd':
        cric_foot= obj.intersection(obj.cric_list, obj.foot_list)
        ans_list = obj.difference(cric_foot, obj.bad_list)
        ans = len(ans_list)
        print("Number of students who play cricket and football but not badminton: ", ans)

    flag = input("Do you want to continue? (1/0)")