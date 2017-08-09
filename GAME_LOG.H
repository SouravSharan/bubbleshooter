#define PI 3.14159265


double **new_move(int coordinates, int &rebound_count, int &destination);
int get_colour(int grid_colour);
double get_line_end(double slope, int c, int row, int col);
int get_rebound_count(double slope,int row,int col);
double **get_line_func(double slope,int row,int col,int rebound_count);

int get_colour(int grid_colour){
	srand(time(NULL));
	int colour=rand()%15;
	if(colour==grid_colour ||colour==0||colour==15)
		get_colour(grid_colour);
	return colour;
}

double get_line_end(double slope, int c, int row, int col){
	double y=0;
	double p_limit=col/2, n_limit=-p_limit;

	if(slope>=0)
		y=(slope*p_limit)+c;
	else if(slope<0)
		y=(slope*n_limit)+c;
	if(y>=row){
		return row;
	}
	return y;
}

int get_rebound_count(double slope,int row,int col){
	int result=1;
	double y = get_line_end(slope,0,row,col);
	int n_y= (int)(y+0.5);
	if(n_y<row){
		result=2;
		double rebound = (row/n_y)-1;
		result += (int)(rebound / 2);
	}
	return result;
}

double **get_line_func(double slope,int row,int col,int rebound_count){
	double x=0,y1=0,y2=0;
	double c=0;
	//getting number of times the ball rebounds for creating array to store the line function
	//int rebound_count = get_rebound_count(angle,row,col);
	//creating the array to store line function
	double **line_func = new double*[rebound_count];
	for(int i=0;i<rebound_count;i++)
		line_func[i] = new double[4];   //m,c,y1,y2

	for(i=0;i<rebound_count;i++){
		//finding out the y coordinate of end point of a line in the equation where the ball rebounds
		y2 = get_line_end(slope,c,row,col);
		line_func[i][0]=slope;
		line_func[i][1]=c;
		line_func[i][2]=y1;
		line_func[i][3]=y2;
		//reseting values for next iteration
		y1 = y2;
		if(slope>=0)
			x=col/2;
		else if(slope<0)
			x=-1*col/2;
		slope=(-1)*slope;
		c=y2-(slope*x);
	}
	return line_func;
}

double **new_move(int *coordinates, int &rebound_count){
	int row=20, col=30;

	double slope = ((double)coordinates[1])/((double)coordinates[0]);
	rebound_count = get_rebound_count(slope,row,col);
	double **line_func = get_line_func(slope,row,col,rebound_count);

	return line_func;
}





