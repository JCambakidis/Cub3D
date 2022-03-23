# Cub3D

This is Cub3D Project of 42 School 

<div align="center">
      <a target="_blank" href="https://www.youtube.com/watch?v=EcaKh0xlXBg">
     <img 
      src="https://img.youtube.com/vi/EcaKh0xlXBg/0.jpg" 
      alt="Cub3D" 
      style="width:50%;">
      </a>
   </div>

Your mission, kill all enemies !!!

Inputs :

- Move : ```W, A, S, D```
- Run : ```Tab Left```
- Rotate Camera : ```←	↑ →	↓```
- Attack : ```Alt Left```
- Jump : ```Space```
- Guard : ```Tab Right```
- Show Mini-Map : ```Shift```

Debug Mode Inputs :

- Activating Debug : ```<```
- Activate Fly Mode : ```end```
- Fly : ```Space```
- Change FOV : ```*, /```
- Change Render Distance : ```+, -```
- Change Pixels Resolution : ```PageUP, PageDown```

Example of map file :
```
1111111111
1000000001
10000100011111
10000000000201
10W00100000001
10000000011111
1111111111
```
Map legend:
```
N,S,E,W : Player location
1,2 : Walls
3 : No collided walls
0 : Empty space
A : Enemy
H : Heal power up
```

In Cube3d Folder use : 
```
./cub3d maps/map.cub
```
or
```
make sh
```

GOOD LUCK !
