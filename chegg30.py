class Employee:

    # this method __init__ of the Employee class executes automatically
    def __init__(self, name, id_number, department, job_title):

        # these data attributes are assigned the values
        self.employee_name = name
        self.employee_id_number = id_number
        self.employee_department = department
        self.employee_job_title = job_title

    # this method __str__ executes automatically and will get the string values of the Employee class
    def __str__(self):
        this_string = "*" * 35 + "\n"
        this_string += "Employee Name: " + self.employee_name + "\n"
        this_string += "Employee ID Number: " + str(self.employee_id_number) + "\n"
        this_string += "Employee Department: " + self.employee_department + "\n"
        this_string += "Employee Job Title: " + self.employee_job_title + "\n"
        this_string += "*" * 35 + "\n"
        return this_string
    def modify(self):
        print("")
        ch = input("Do you want to change the name(y/n): ")
        if ch == "y":
            self.employee_name = input("Enter new name: ")
        ch = input("Do you want to change the department(y/n): ")
        if ch == "y":
            self.employee_department = input("Enter new department: ")
        ch = input("Do you want to change the job title(y/n): ")
        if ch == "y":
            self.employee_job_title = input("Enter new job title: ")
d = {}
one = 0
for i in range(3):
    name = input("Enter Employee name: ")
    id_num = int(input("Enter Employee id: "))
    dep = input("Enter department: ")
    job = input("Enter job title: ")
    temp = Employee(name,id_num,dep,job)
    d[id_num] = temp
    one = id_num
d[one].modify()
print(d[one])
