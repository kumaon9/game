#include<bits/stdc++.h>
using namespace std;

#define N 8

class Util
{
public:
	void move(int currX, int currY, int xStep, int yStep, int totalSteps){
		char  alphabets[6] = {'A' , 'B' , 'C' , 'D' , 'E', 'F' };
		totalSteps = min(totalSteps,N-1);
		// todo and use checkBounds
		for(int i=0;i<totalSteps;i++){
			currX+=xStep;
			currY+=yStep;
			if(!checkBounds(currX,currY)) return;
			cout<<alphabets[currX]<<","<<currY<<endl;
		}
	}

	bool checkBounds(int x, int y){
		if(x<0 || x>=8) return false;
		if(y<0 || y>=8) return false;
		return true;
	}
};



class Piece
{
public:
	Util util;
	 virtual void possibleMoves(){
	 };
	
};

class King : public Piece {

public:
	void possibleMoves(int i, int j){
		// cout<<"Possible moves works\n";
		util.move(i,j,1,1,1);
		util.move(i,j,1,-1,1);
		util.move(i,j,-1,1,1);
		util.move(i,j,-1,-1,1);

		util.move(i,j,1,0,1);
		util.move(i,j,0,1,1);
		util.move(i,j,-1,0,1);
		util.move(i,j,0,-1,1);
	}
};

class Queen : public Piece {

public:
	void possibleMoves(int i, int j){
	
		util.move(i,j,1,1,INT_MAX);
		util.move(i,j,1,-1,INT_MAX);
		util.move(i,j,-1,1,INT_MAX);
		util.move(i,j,-1,-1,INT_MAX);


		util.move(i,j,1,0,INT_MAX);
		util.move(i,j,0,1,INT_MAX);
		util.move(i,j,-1,0,INT_MAX);
		util.move(i,j,0,-1,INT_MAX);	
	}
};

class Bishop : public Piece {

public:
	void possibleMoves(int i, int j){
		
		util.move(i,j,1,1,INT_MAX);
		util.move(i,j,1,-1,INT_MAX);
		util.move(i,j,-1,1,INT_MAX);
		util.move(i,j,-1,-1,INT_MAX);
	}
};

class Knight : public Piece {

public:
	void possibleMoves(int i, int j){
		
		util.move(i,j,2,1,1);
		util.move(i,j,1,2,1);
		util.move(i,j,-2,1,1);
		util.move(i,j,-1,2,1);
		util.move(i,j,2,-1,1);
		util.move(i,j,1,-2,1);
		util.move(i,j,-2,-1,1);
		util.move(i,j,-1,-2,1);
	}
};

class Rook : public Piece {

public:
	void possibleMoves(int i, int j){

		util.move(i,j,1,0,1);
		util.move(i,j,0,1,1);
		util.move(i,j,-1,0,1);
		util.move(i,j,0,-1,1);
		
	}
};


class Pawn : public Piece {

public:
	void possibleMoves(int i, int j){
		
		util.move(i,j,1,1,1);
	}
};

class Chess{

	public:
		Util util;

		Chess(){
			cout<<"hello\n";
		}
		void query(string piece, string cell){
			//todo
			// parse the cell into integers
			int i = cell[0]-'A';
			int j = cell[1]-'0';
			// cout<<i<<" "<<j<<endl;
			if(!util.checkBounds(i,j)){
				cout<<"invalid query\n";
				return;
			}

			//select a piece to move
			if(piece=="King"){
				King p;
				p.possibleMoves(i,j);
			} else if(piece=="Queen"){
				Queen q;
				q.possibleMoves(i,j);

			} else if(piece=="Rook"){
				//Rook p;
				//p.possibleMoves(i,j);

			} else if(piece=="Bishop"){
				//Bishop p;
				//p.possibleMoves(i,j);

			} else if(piece=="Knight"){
				Knight k;
				k.possibleMoves(i,j);

			} else if(piece=="Pawn"){
				//Pawn p;
				//p.possibleMoves(i,j);

			} else{cout<<"invalid query\n";}
		}

		// we need a fucntion called move which will be overrided by pieces
		

};
int main(){
	Chess chessobject;

	//chessobject.query("King", "A5");
	chessobject.query("Knight", "D4");
	// King k;
	// k.possibleMoves();

}