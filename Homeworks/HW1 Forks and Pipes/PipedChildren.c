int main()
{
	//fork() declaration section
	if(pid==0){
		printf("the first child\n");
	}
	else if(pid>0){
		printf("the first parent\n");
		wait();
	}
	
	if(pid1==0){
		printf("the second child\n");
	}
	else if(pid>0){
		printf("the second parent\n");
		wait();
	}
	return 0;
}
