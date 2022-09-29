class SJF:
    process_data = []#I have kept one list of processes for SJF class
    def processData(self):#We add one process when input A is given
        temporary = []
        process_id = int(input("Enter Process ID: "))
        burst_time = int(input(f"Enter Burst Time for Process {process_id}: "))
        temporary.extend([process_id, 0, burst_time, 0, burst_time])
        '''
        '0' is the state of the process. 0 means not executed and 1 means execution complete
        '''
        self.process_data.append(temporary)#we add the process

    def schedulingProcess(self):#We execute all the processes that are in process_data when E input is given
        if len(self.process_data) == 0:#If there are no processes we return
            print("There are no processes in the queue.")
            return
        start_time = []
        exit_time = []
        s_time = 0
        sequence_of_process = []
        while 1:
            ready_queue = []
            temp = []
            for i in range(len(self.process_data)):#
                if self.process_data[i][1] <= s_time and self.process_data[i][3] == 0:
                    temp.extend([self.process_data[i][0], self.process_data[i][1], self.process_data[i][2], self.process_data[i][4]])
                    ready_queue.append(temp)
                    temp = []
            if len(ready_queue) == 0:
                break
            if len(ready_queue) != 0:
                ready_queue.sort(key=lambda x: x[2])
                '''
                Sort processes according to Burst Time
                '''
                start_time.append(s_time)
                s_time = s_time + 1
                e_time = s_time
                exit_time.append(e_time)
                sequence_of_process.append(ready_queue[0][0])
                for k in range(len(self.process_data)):
                    if self.process_data[k][0] == ready_queue[0][0]:
                        break
                self.process_data[k][2] = self.process_data[k][2] - 1
                if self.process_data[k][2] == 0:        #If Burst Time of a process is 0, it means the process is completed
                    self.process_data[k][3] = 1
                    self.process_data[k].append(e_time)
        t_time = SJF.calculateTurnaroundTime(self)
        w_time = SJF.calculateWaitingTime(self)
        SJF.printData(self, t_time, w_time, sequence_of_process)
        self.process_data = []#After executing the processes, there are no processes in the queue. So we remove all the processes

    def calculateTurnaroundTime(self):
        total_turnaround_time = 0
        for i in range(len(self.process_data)):
            turnaround_time = self.process_data[i][5] - self.process_data[i][1]
            '''
            turnaround_time = completion_time - arrival_time
            '''
            total_turnaround_time = total_turnaround_time + turnaround_time
            self.process_data[i].append(turnaround_time)
        average_turnaround_time = total_turnaround_time / len(self.process_data)
        '''
        average_turnaround_time = total_turnaround_time / no_of_processes
        '''
        return average_turnaround_time

    def calculateWaitingTime(self):
        total_waiting_time = 0
        for i in range(len(self.process_data)):
            waiting_time = self.process_data[i][6] - self.process_data[i][4]
            '''
            waiting_time = turnaround_time - burst_time
            '''
            total_waiting_time = total_waiting_time + waiting_time
            self.process_data[i].append(waiting_time)
        average_waiting_time = total_waiting_time / len(self.process_data)
        '''
        average_waiting_time = total_waiting_time / no_of_processes
        '''
        return average_waiting_time

    def printData(self, average_turnaround_time, average_waiting_time, sequence_of_process):
        self.process_data.sort(key=lambda x: x[0])
        '''
        Sort processes according to the Process ID
        '''
        print("Process_ID  Arrival_Time  Rem_Burst_Time      Completed  Orig_Burst_Time Completion_Time  Turnaround_Time  Waiting_Time")
        for i in range(len(self.process_data)):
            for j in range(len(self.process_data[i])):
                print(self.process_data[i][j], end="\t\t\t\t")
            print()
        print(f'Average Turnaround Time: {average_turnaround_time}')
        print(f'Average Waiting Time: {average_waiting_time}')
        print(f'Sequence of Process: {sequence_of_process}')


if __name__ == "__main__":
    sjf = SJF()
    while(1):
        ch = input("Please enter input:\n E To execute the processes\n A To add a process\n X To exit the program\n: ")#Taking the input
        if ch == "E":
            sjf.schedulingProcess()#Ececuting the processes
        elif ch == "A":
            sjf.processData()#Adding a process
        elif ch == "X":#Exit the program
            break
        else:#If any other inputs are given, we prompt the user.
            print("Wrong input entered.")
            
