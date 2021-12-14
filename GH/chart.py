import matplotlib.pyplot as plt

def main():
    x = range(1, 1000002, 10000)
    # graph 1
    list1 = []
    list2 = []
    
    with open('№1.txt', 'r') as file:
        list1.extend(map(int, file.readlines()))
    with open('№2.txt', 'r') as file:
        list2.extend(map(int, file.readlines()))
    
    fig, ax = plt.subplots()

    ax.plot(x, list1)
    ax.plot(x, list2)
    ax.set_title('Trial: 1, mode: 1')
    ax.set_xlabel('n')
    ax.set_ylabel('T(n), mcs')
    ax.grid(True, 'both', 'both')
    ax.legend(['quick sort', 'AVL tree'])

    fig.tight_layout()
    fig.savefig('graph1.png')

    # graph 2
    list1 = []
    list2 = []
    
    with open('№3.txt', 'r') as file:
        list1.extend(map(int, file.readlines()))
    with open('№4.txt', 'r') as file:
        list2.extend(map(int, file.readlines()))

    fig, ax = plt.subplots()

    ax.plot(x, list1)
    ax.plot(x, list2)
    ax.set_title('Trial: 1, mode: 2')
    ax.set_xlabel('n')
    ax.set_ylabel('T(n), mcs')
    ax.grid(True, 'both', 'both')
    ax.legend(['quick sort', 'AVL tree'])

    fig.tight_layout()
    fig.savefig('graph2.png')

    # graph 3
    x = range(0, 1000001, 10000)
    list1 = []
    list2 = []
    
    with open('№5.txt', 'r') as file:
        list1.extend(map(int, file.readlines()))
    with open('№6.txt', 'r') as file:
        list2.extend(map(int, file.readlines()))

    fig, ax = plt.subplots()

    ax.plot(x, list1)
    ax.plot(x, list2)
    ax.set_title('Trial: 2, mode: 1')
    ax.set_xlabel('q, w')
    ax.set_ylabel('T(n), mcs')
    ax.grid(True, 'both', 'both')
    ax.legend(['quick sort', 'AVL tree'])

    fig.tight_layout()
    fig.savefig('graph3.png')
    
    # graph 4
    list1 = []
    list2 = []
    
    with open('№7.txt', 'r') as file:
        list1.extend(map(int, file.readlines()))
    with open('№8.txt', 'r') as file:
        list2.extend(map(int, file.readlines()))

    fig, ax = plt.subplots()

    ax.plot(x, list1)
    ax.plot(x, list2)
    ax.set_title('Trial: 2, mode: 2')
    ax.set_xlabel('q, w')
    ax.set_ylabel('T(n), mcs')
    ax.grid(True, 'both', 'both')
    ax.legend(['quick sort', 'AVL tree'])

    fig.tight_layout()
    fig.savefig('graph4.png')

if __name__ == '__main__':
    main()
