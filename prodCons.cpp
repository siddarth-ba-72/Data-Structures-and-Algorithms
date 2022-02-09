// * PRODUCER CONSUMER PROBLEM USING BUFFER, CIRCULAR QUEUE DATA STRUCTURE

#include <iostream>
using namespace std;
#define BUFFER_SIZE 5

// * Buffer structure
struct BUFFER
{
	int front;
	int rear;
	int size;
	int capacity;
	int *arr;
};

// * Consumer structure
struct CONSUMER
{
	int *arr;
	int size;
	int idx;
};

typedef struct BUFFER *Buffer;
typedef struct CONSUMER *Consumer;

// * New Buffer
Buffer createBuffer()
{
	Buffer buffer = new BUFFER;
	buffer->capacity = BUFFER_SIZE;
	buffer->size = 0;
	buffer->front = 0;
	buffer->rear = BUFFER_SIZE - 1;
	buffer->arr = (int *)malloc(buffer->capacity * sizeof(int));
	return buffer;
}

// * Consumer Array
Consumer createConsumer()
{
	Consumer consumer = new CONSUMER;
	consumer->size = BUFFER_SIZE;
	consumer->idx = -1;
	consumer->arr = (int *)malloc(BUFFER_SIZE * sizeof(int));
	return consumer;
}

// * Check if BUFFER is Full
bool isFullBuffer(Buffer buffer)
{
	return (buffer->size == buffer->capacity);
}

// * Check if CONSUMER is Full
bool isFullConsumer(Consumer consumer)
{
	return (consumer->idx == consumer->size - 1);
}

// * Check if BUFFER is Empty
bool isEmptyBuffer(Buffer buffer)
{
	return (buffer->size == 0);
}

// * Check if CONSUMER is Empty
bool isEmptyConsumer(Consumer consumer)
{
	return (consumer->size == 0);
}

// * Function to enable the PRODUCER to add the item to buffer iff buffer is not full
void addItem(Buffer buffer, int item)
{
	if (isFullBuffer(buffer))
	{
		cout << "Buffer is full. Wait for the consumer to receive the item." << endl;
		return;
	}
	cout << "Enter the item to be added: ";
	cin >> item;
	buffer->rear = (buffer->rear + 1) % buffer->capacity;
	buffer->arr[buffer->rear] = item;
	buffer->size++;
}

// * Function for CONSUMER to remove the item from buffer iff buffer is not empty
int removeItem(Buffer buffer, Consumer consumer)
{
	if (isEmptyBuffer(buffer))
	{
		cout << "Buffer is empty. Wait for the producer to add an item." << endl;
		return -1;
	}
	int item = buffer->arr[buffer->front];
	buffer->front = (buffer->front + 1) % buffer->capacity;
	buffer->size--;
	if (isFullConsumer(consumer))
	{
		consumer->arr = (int *)realloc(consumer->arr, (++consumer->size) * sizeof(int));
	}
	consumer->arr[++consumer->idx] = item;
	return item;
}

// * Function to display the items in buffer
void displayBuffer(Buffer buffer)
{
	if (isEmptyBuffer(buffer))
	{
		cout << "Buffer is empty" << endl;
		return;
	}
	int i = buffer->front;
	while (i != buffer->rear)
	{
		cout << buffer->arr[i] << " ";
		i = (i + 1) % buffer->capacity;
	}
	cout << buffer->arr[i] << endl;
}

// * Function to display the contents already recieved by the consumer
void displayConsumer(Consumer consumer)
{
	if (isEmptyConsumer(consumer))
	{
		cout << "Consumer is empty" << endl;
		return;
	}
	for (int i = 0; i <= consumer->idx; i++)
	{
		cout << consumer->arr[i] << " ";
	}
	cout << endl;
}

void displayIntro()
{
	printf("\n------PRODUCER-CONSUMER------\n");
	printf("Press 1 for producer to add an item into the buffer\n");
	printf("Press 2 for consumer to remove an item from the buffer\n");
	printf("Press 3 to display the buffer\n");
	printf("Press 4 to display the items already recieved by the consumer\n");
	printf("Press 5 to exit\n");
	printf("-----------------------------------------------\n");
}

int main()
{
	displayIntro();

	Buffer buffer = createBuffer();
	Consumer consumer = createConsumer();

	int choice, item;
	while (1)
	{
	f:
		cout << "\nEnter your choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			cout << "Producer is trying to add an item into the buffer" << endl;
			addItem(buffer, item);
			cout << "BUFFER: ";
			displayBuffer(buffer);
			cout << endl;
			break;

		case 2:
			cout << "Consumer is trying to remove an item from the buffer" << endl;
			item = removeItem(buffer, consumer);
			if (item == -1)
				cout << "Removed item is: NULL" << endl;
			else
				cout << "Removed item is: " << item << endl;
			cout << "BUFFER: ";
			displayBuffer(buffer);
			cout << "CONSUMER: ";
			displayConsumer(consumer);
			cout << endl;
			break;

		case 3:
			cout << "BUFFER: ";
			displayBuffer(buffer);
			cout << endl;
			break;

		case 4:
			cout << "CONSUMER: ";
			displayConsumer(consumer);
			cout << endl;
			break;

		case 5:
			cout << "Exiting..." << endl;
			exit(0);

		default:
			cout << "Invalid choice" << endl;
			goto f;
		}
	}

	return 0;
}
