#include"queue.h"

bool queue::isempty()
{
	return front==rear;
 } 
 
 bool queue::isfull()
 {
 	return (front==0)&&(rear==MAX);
 }
 
 bool queue::push(const item& i)
 {
	if(!isfull())
	{
		items[rear++]=i;
	}
	else return false;
	
	return true;
 }
 
bool queue::pop(item& i)
{
	if(!isempty())
	{
		i=items[front--];
	}
	else return false;
	
	return true;
}

queue::queue()
{
	front=rear=0;
}
