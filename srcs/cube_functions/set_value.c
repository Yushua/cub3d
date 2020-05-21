#include "cube.h"

void		set_value(t_struct_m *main)
{
//for raycasting

	//where in the box we are
	// main->Ray.sideDistX
	// main->Ray.sideDisty

	// main->Ray.deltaDistX
	// main->Ray.deltaDistY;
	// main->Ray.perpwallDist;

	// main->Ray.stepX
	// main->Ray.stepY

	// main->Ray.side


	// main->Ray.posX = 0;
	// main->Ray.posY = 0;

	// main->Ray.dirY = 1;
	// main->Ray.dirX = -1;
	
	// main->Ray.planeX = -0.66;
	// main->Ray.planeY = 0;

//cube
	main->place.x = 100;//position
	main->place.y = 100;//position
	main->place.w = 100;//width
	main->place.h = 100;//height
	main->place.col = 0xFFFF0000;

//map
	main->place.s_width = -1;
	main->place.s_height = -1;
	main->place.dir = -1; // if -1, give error
	main->place.Fcol1 = -1;
	main->place.Fcol2 = -1;
	main->place.Fcol3 = -1;
	main->place.Ccol1 = -1;
	main->place.Ccol2 = -1;
	main->place.Ccol3 = -1;

	main->place.error = -1;
	main->place.error_c = 1;
	main->place.error_n = 0;
	main->place.check_double = 0;

//for cube
	main->place.x = 100;//position
	main->place.y = 100;//position
	main->place.w = 100;//width
	main->place.h = 100;//height
	main->place.col = 0xFFFF0000;
	main->place.s_width = 1200;
	main->place.s_height = 800;


//CHECK MAP DOUBLE
	main->Double.D_R = 0;
	main->Double.D_NO = 0;
	main->Double.D_SO = 0;
	main->Double.D_WE = 0;
	main->Double.D_EA = 0;
	main->Double.D_S = 0;
	main->Double.D_F = 0;
	main->Double.D_C = 0;

//strings
	main->place.NO = NULL;
	main->place.SO = NULL;
	main->place.EA = NULL;
	main->place.S  = NULL;
	main->place.WE = NULL;
//map checks

	main->place.mapx = 0;
	main->place.mapy = 0;
	main->place.mapp = 0;
	main->place.mapE = 0;
	main->place.mapc = -1;

	main->place.cubemap = NULL;
}