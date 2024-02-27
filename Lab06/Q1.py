class CircularQueue():
    def __init__(self, capacity):
        self.capacity = capacity
        self.queue = [None] * capacity
        self.begin = 0
        self.end = 0
        self.size = 0

    def enqueue(self, item):
        if self.size == self.capacity:
            print("Queue is full. Cannot enqueue more items.")
            return
        self.queue[self.end] = item
        self.end = (self.end + 1) % self.capacity
        self.size += 1

    def dequeue(self):
        if self.size == 0:
            print("Queue is empty. Cannot dequeue.")
            return None
        item = self.queue[self.begin]
        self.queue[self.begin] = None
        self.begin = (self.begin + 1) % self.capacity
        self.size -= 1
        return item


    def build(self, start, lst):
        self.begin = start
        ticker = 0
        for i in range(len(lst)):
            if i + start < 5:
                self.indices[i + start] = lst[i]
                self.end = i + start
            else:
                self.indices[ticker] = lst[i]
                self.end = ticker
                ticker += 1

    def show(self):
        print("0 1 2 3 4")
        print(self.queue)
        print(self.begin)
        print(self.end)


    # def enq(self, val):
    #     ticker = 0

    #     if "" not in self.indices:
    #         print("bros full")
    #         return 0

    #     for i in range(5):
    #         if i + self.begin < 5:
                
    #             if (self.indices[i + self.begin] == ""):
    #                 self.end = i + self.begin
    #                 self.indices[i + self.begin] = val
    #         else:
    #             if (self.indices[ticker] == ""):
    #                 self.end = ticker
    #                 self.indices[ticker] = val
    #             ticker += 1
    # def deq(self):
    #     if self.indices == ["", "", "", "", ""]:
    #         print("bros empty")
    #         return 0
        
    #     self.indices[self.end] = ""

    #     if self.end == 0:
    #         self.end = 4
    #     else:
    #         self.end -= 1

    def __lt__(self, other):
        current_self = self.begin
        current_other = other.begin
        for _ in range(min(self.size, other.size)):
            if self.queue[current_self] < other.queue[current_other]:
                return True
            elif self.queue[current_self] > other.queue[current_other]:
                return False
            current_self = (current_self + 1) % self.capacity
            current_other = (current_other + 1) % other.capacity
        return self.size < other.size
        




# Call the build method
q1 = CircularQueue(6)
q2 = CircularQueue(6)
q3 = CircularQueue(6)

q1.enqueue(1)
q1.enqueue(5)
q1.enqueue(5)

q2.enqueue(2)
q2.enqueue(1)
q2.enqueue(5)

q3.enqueue(11)
q3.enqueue(2)


queues = [q1, q2, q3]
sorted_queues = sorted(queues)

for queue in sorted_queues:
    queue.show()