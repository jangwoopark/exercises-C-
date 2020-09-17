#include <bits/stdc++.h>

using namespace std;

int sgn( int x ) {
    if( x==0 ) return 0;
    return ( x < 0 ? -1 : 1 );
}

struct point {
    int x, y;

    point() : x(0), y(0) {}
    point( int a, int b) : x(a), y(b) {}

    bool operator == (const point &p ) const { return (x==p.x && y==p.y);}
    void operator *= (const int k ) { this->x *= k; this->y *= k; }

    point operator - (const point &p ) const { return point(x-p.x, y-p.y); }
    point operator + (const point &p ) const { return point(x+p.x, y+p.y); }

    point rotate ( ) { return point( -y, x ); }
    int distance( const point &p ) const { return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y); }
    int cross( const point &p ) const { return x*p.y - p.x*y; }
};

int n, m, radius;
point centerCircle;
vector<point> rectangule( 5 );

bool isInCircle( const point &p ) {
    return (p.distance( centerCircle ) <= radius*radius);
}

void buildRectangule( int x1, int y1, int x2, int y2){
    point centerRectangule((x1+x2)/2, (y1+y2)/2);

    rectangule[ 0 ] = point(x1,y1);
    rectangule[ 1 ] = centerRectangule + (rectangule[ 0 ] - centerRectangule).rotate();
    rectangule[ 2 ] = point(x2,y2);
    rectangule[ 3 ] = centerRectangule + (rectangule[ 2 ] - centerRectangule).rotate();
    rectangule[ 4 ] = rectangule[ 0 ];
}

bool isInRectangule( const point &p ) {
    int sgns[ 4 ];
    for( int i = 0; i < 4; ++i ) {
        point vector1 = rectangule[ i+1 ] - rectangule[ i ];
        point vector2 = p - rectangule[ i ];
        sgns[ i ] = sgn( vector1.cross(vector2) );
    }
		
		// the sign of parallel edges have to be the same or 0
    return ( sgns[ 0 ]*sgns[ 2 ] >= 0 && sgns[ 1 ]*sgns[ 3 ] >= 0);
}

int main() {
    int x1,y1,x2,y2;
    cin >> m >> n;

    cin >> centerCircle.y >> centerCircle.x >> radius;
    centerCircle *= 10; radius *= 10;
    
    cin >> y1 >> x1 >> y2 >> x2;
    buildRectangule(x1*10, y1*10, x2*10, y2*10);

    point current;
    for( int x=0; x < n; ++x ) {
        for( int y=0; y < m; ++y ) {
            current = point( x, y );
            current *= 10;

            if( isInCircle( current ) || isInRectangule( current ) )
                cout << "#";
            else
                cout << ".";
        }
        cout << endl;
    }
    return 0;
}
