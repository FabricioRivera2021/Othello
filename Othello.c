#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct {
  int x;
  int y;
  char ficha;
  bool empty;
} coordenada;

typedef struct {
  coordenada coord_inicio;
  coordenada coord_fin[3];//a lo sumo 3 coordenadas al mismo tiempo
  char direccion[20];
  bool isPlay;
} jugadaPosible;

typedef struct {
  coordenada jugada[64];
  int coordenada_id; //id de la casilla "64" casillas posibles
} tablero;

typedef struct {
  int id;
  char nombre[60]; 
  char ficha; //ficha que este usando el jugador
  int turno; //contador de turnos
  bool ultimoTurno; //para saber quien tuvo el ultimo turno
} jugador;

void iniciarPlays (jugadaPosible plays[]){
  for(int i = 0; i < 64; i++){
      plays[i].coord_inicio.x = 0;
      plays[i].coord_inicio.y = 0;
      plays[i].coord_fin[0].x = 0;
      plays[i].coord_fin[0].y = 0;
      plays[i].coord_fin[1].x = 0;
      plays[i].coord_fin[1].y = 0;
      plays[i].coord_fin[2].x = 0;
      plays[i].coord_fin[2].y = 0;
      plays[i].isPlay = false;
  }

  printf("LINEA 47 Jugadas iniciadas con exito\n");
}

void showPlays (jugadaPosible plays[]){
  for(int i = 0; i < 64; i++){
    if(plays[i].isPlay == 1){
      printf("\n-> jugada valida en:\n [%d - %d]\njugada1|%d - %d|\njugada2|%d - %d|\njugada3|%d - %d|\nEs jugada: %d\n", 
        // i,
        plays[i].coord_inicio.x,
        plays[i].coord_inicio.y,
        plays[i].coord_fin[0].x,
        plays[i].coord_fin[0].y,
        plays[i].coord_fin[1].x,
        plays[i].coord_fin[1].y,
        plays[i].coord_fin[2].x,
        plays[i].coord_fin[2].y,
        // plays[0].direccion,
        plays[i].isPlay
      );
    }
  }
}

void savePlays(jugadaPosible plays[], int index, int x, int y, int fin_x, int fin_y, char direccion[]){
  for (int i = 0; i < 64; i++){
    //quiere decir que es un espacio vacio para guardar
    if(plays[i].isPlay == 0){ 
      plays[i].coord_inicio.x = x;
      plays[i].coord_inicio.y = y;
      plays[i].coord_fin[0].x = fin_x;
      plays[i].coord_fin[0].y = fin_y;
      plays[i].isPlay = 1;
      // strcpy(plays[i].direccion, direccion);
      break;
    //quiere decir que para ese valor de origen existen mas direcciones de jugadas posibles
    }
    else if(plays[i].coord_inicio.x == x && plays[i].coord_inicio.y == y){
      if(plays[i].coord_fin[1].x == 0 && plays[i].coord_fin[1].y == 0){
        plays[i].coord_fin[1].x = fin_x;
        plays[i].coord_fin[1].y = fin_y;
        break;
      }else{
        plays[i].coord_fin[2].x = fin_x;
        plays[i].coord_fin[2].y = fin_y;
        break;
      }
    }
  }
}

//LUEGO DE ENCONTRAR CASILLAS ADYACENTES SEGUIR BUSCANDO EN LA DIRECCION QUE CORRESPONDA
void find(tablero* tab, int x, int y, int direccion, char ficha, char ficha_oponente, jugadaPosible plays[]){
  int offset = 1;
  int l = 0;
  if(direccion == 4){
    while(l < 64){
        if(tab->jugada[l].x == x && tab->jugada[l].y == y - offset){
          if(y - offset == 0){
            printf("fuera de tablero \n");
            break; //fuera de tablero. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == ficha){
            printf("ficha del jugador actual \n");
            break; //ficha igual al del jugador. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == '_'){
            //guardar la play
            savePlays(plays, l, x, y, tab->jugada[l].x, tab->jugada[l].y, "horizontal-");
            break;
          }else if(tab->jugada[l].ficha == ficha_oponente){
            //Ficha oponente encontrada en %d %d, seguir buscando
            offset++;
            l = 0;
          }
        }
    l++;
    }
  }else if(direccion == 7){
    while(l < 64){
        if(tab->jugada[l].x == x + offset && tab->jugada[l].y == y){
          if(x + offset == 9){
            printf("fuera de tablero \n");
            break; //fuera de tablero. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == ficha){
            printf("ficha del jugador actual \n");
            break; //ficha igual al del jugador. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == '_'){
            savePlays(plays, l, x, y, tab->jugada[l].x, tab->jugada[l].y, "vertical-");
            break;
          }else if(tab->jugada[l].ficha == ficha_oponente){
            //Ficha oponente encontrada en %d %d, seguir buscando
            offset++;
            l = 0;
          }
        }
    l++;
    }
  }else if (direccion == 1){
    while(l < 64){
        if(tab->jugada[l].x == x - offset && tab->jugada[l].y == y - offset){
          if(y - offset == 0 || x - offset == 0){
            printf("fuera de tablero \n");
            break; //fuera de tablero. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == ficha){
            printf("ficha del jugador actual \n");
            break; //ficha igual al del jugador. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == '_'){
            savePlays(plays, l, x, y, tab->jugada[l].x, tab->jugada[l].y, "diag_sup_izq");
            break;
          }else if(tab->jugada[l].ficha == ficha_oponente){
            //Ficha oponente encontrada en %d %d, seguir buscando
            offset++;
            l = 0;
          }
        }
    l++;
    }
  }else if (direccion == 2){
    while(l < 64){
        if(tab->jugada[l].x == x - offset && tab->jugada[l].y == y){
          if(x - offset == 0){
            printf("fuera de tablero \n");
            break; //fuera de tablero. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == ficha){
            printf("ficha del jugador actual \n");
            break; //ficha igual al del jugador. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == '_'){
            savePlays(plays, l, x, y, tab->jugada[l].x, tab->jugada[l].y, "vertical+");
            break;
          }else if(tab->jugada[l].ficha == ficha_oponente){
            //Ficha oponente encontrada en %d %d, seguir buscando
            offset++;
            l = 0;
          }
        }
    l++;
    }
  }else if (direccion == 3){
    while(l < 64){
        if(tab->jugada[l].x == x - offset && tab->jugada[l].y == y + offset){
          if(x - offset == 0 || y + offset == 9){
            printf("fuera de tablero \n");
            break; //fuera de tablero. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == ficha){
            printf("ficha del jugador actual \n");
            break; //ficha igual al del jugador. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == '_'){
            savePlays(plays, l, x, y, tab->jugada[l].x, tab->jugada[l].y, "diag_sup_der");
            break;
          }else if(tab->jugada[l].ficha == ficha_oponente){
            //Ficha oponente encontrada en %d %d, seguir buscando
            offset++;
            l = 0;
          }
        }
    l++;
    }
  }else if (direccion == 5){
    while(l < 64){
        if(tab->jugada[l].x == x && tab->jugada[l].y == y + offset){
          if(y + offset == 9){
            printf("fuera de tablero \n");
            break; //fuera de tablero. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == ficha){
            printf("ficha del jugador actual \n");
            break; //ficha igual al del jugador. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == '_'){
            savePlays(plays, l, x, y, tab->jugada[l].x, tab->jugada[l].y, "horizontal+");
            break;
          }else if(tab->jugada[l].ficha == ficha_oponente){
            //Ficha oponente encontrada en %d %d, seguir buscando
            offset++;
            l = 0;
          }
        }
    l++;
    }
  }else if (direccion == 6){
    while(l < 64){
        if(tab->jugada[l].x == x + offset && tab->jugada[l].y == y - offset){
          if(x + offset == 9 || y - offset == 0){
            printf("fuera de tablero \n");
            break; //fuera de tablero. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == ficha){
            printf("ficha del jugador actual \n");
            break; //ficha igual al del jugador. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == '_'){
            savePlays(plays, l, x, y, tab->jugada[l].x, tab->jugada[l].y, "diag_inf_izq");
            break;
          }else if(tab->jugada[l].ficha == ficha_oponente){
            //Ficha oponente encontrada en %d %d, seguir buscando
            offset++;
            l = 0;
          }
        }
    l++;
    }
  }else if (direccion == 8){
    while(l < 64){
        if(tab->jugada[l].x == x + offset && tab->jugada[l].y == y + offset){
          if(x + offset == 9 || y + offset == 9){
            printf("fuera de tablero \n");
            break; //fuera de tablero. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == ficha){
            printf("ficha del jugador actual \n");
            break; //ficha igual al del jugador. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == '_'){
            savePlays(plays, l, x, y, tab->jugada[l].x, tab->jugada[l].y, "diag_inf_der");
            break;
          }else if(tab->jugada[l].ficha == ficha_oponente){
            //Ficha oponente encontrada en %d %d, seguir buscando
            offset++;
            l = 0;
          }
        }
    l++;
    }
  }
}

//ECONTRAR CASILLAS ADYACENTES
void findPlay(jugador* player, tablero* tab, int x, int y, jugadaPosible plays[]){
  coordenada result;
  char ficha_oponente;
  int i = 0;
  int j = 0;
  while(i < 64){
    if (tab->jugada[i].x == x && tab->jugada[i].y == y){
      result.x = tab->jugada[i].x;
      result.y = tab->jugada[i].y;
      result.ficha = tab->jugada[i].ficha;
      result.empty = false;
      break;
    }
    i++;
  }
  if(result.ficha == 'X'){
    ficha_oponente = 'O';
  }else if(result.ficha == 'O'){
    ficha_oponente = 'X';
  }

  while(j < 64){
    //diagonal sup izq
    if (tab->jugada[j].x == result.x - 1 && tab->jugada[j].y == result.y - 1 && tab->jugada[j].ficha == ficha_oponente){
      printf("1 - [%d - %d] | ORIGEN: %d |\n", tab->jugada[j].x, tab->jugada[j].y, j);
      find(tab, result.x, result.y, 1, player->ficha, ficha_oponente, plays);
      // repetido++;
    }
    //arriba
    if (tab->jugada[j].x == result.x - 1 && tab->jugada[j].y == result.y && tab->jugada[j].ficha == ficha_oponente){
      printf("2 - [%d - %d] | ORIGEN: %d |\n", tab->jugada[j].x, tab->jugada[j].y, j);
      find(tab, result.x, result.y, 2, player->ficha, ficha_oponente, plays);
      // repetido++;
    }
    //diagonal sup der
    if (tab->jugada[j].x == result.x - 1 && tab->jugada[j].y == result.y + 1 && tab->jugada[j].ficha == ficha_oponente){
      printf("3 - [%d - %d] | ORIGEN: %d |\n", tab->jugada[j].x, tab->jugada[j].y, j);
      find(tab, result.x, result.y, 3, player->ficha, ficha_oponente, plays);
      // repetido++;
    }
    //derecha 
    if (tab->jugada[j].x == result.x && tab->jugada[j].y == result.y + 1 && tab->jugada[j].ficha == ficha_oponente){
      printf("4 - [%d - %d] | ORIGEN: %d |\n", tab->jugada[j].x, tab->jugada[j].y, j);
      find(tab, result.x, result.y, 5, player->ficha, ficha_oponente, plays);
      // repetido++;
    }
    //izquierda
    if (tab->jugada[j].x == result.x && tab->jugada[j].y == result.y - 1 && tab->jugada[j].ficha == ficha_oponente){
      printf("5 - [%d - %d] | ORIGEN: %d |\n", tab->jugada[j].x, tab->jugada[j].y, j);
      find(tab, result.x, result.y, 4, player->ficha, ficha_oponente, plays);
      // repetido++;
    }
    //diagonal inf izq -- --
    if (tab->jugada[j].x == result.x + 1 && tab->jugada[j].y == result.y - 1 && tab->jugada[j].ficha == ficha_oponente){
      printf("6 - [%d - %d] | ORIGEN: %d |\n", tab->jugada[j].x, tab->jugada[j].y, j);
      find(tab, result.x, result.y, 6, player->ficha, ficha_oponente, plays);
      // repetido++;
    }
    //abajo -- -- --
    if (tab->jugada[j].x == result.x + 1 && tab->jugada[j].y == result.y && tab->jugada[j].ficha == ficha_oponente){
      printf("7 - [%d - %d] | ORIGEN: %d |\n", tab->jugada[j].x, tab->jugada[j].y, j);
      find(tab, result.x, result.y, 7, player->ficha, ficha_oponente, plays);
      // repetido++;
    }
    //diagonal inf der -- --
    if (tab->jugada[j].x == result.x + 1 && tab->jugada[j].y == result.y + 1 && tab->jugada[j].ficha == ficha_oponente){
      printf("8 - [%d - %d] | ORIGEN: %d |\n", tab->jugada[j].x, tab->jugada[j].y, j);
      find(tab, result.x, result.y, 8, player->ficha, ficha_oponente, plays);
      // repetido++;
    }
    j++;
  }

  /*
  // direccion: 
    1DIAG-SUP-IZQ | 2ARRIBA  | 3DIAG-SUP-DER 
    [-1 -1 ]      | [-1 0]   | [-1 +1]
    --------------|----------|--------------
    4H-IZQ        |          | 5H-DER
    [0 -1]        |   [*]    | [0 +1]
    --------------|----------|-------------
    6DIAG-INF-IZQ | 7-ABAJO  | 8V-INF-DER
    [+1 -1]       | [+1 0]   | [+1 +1]
  */
}

//vALIDAR QUE LA JUGADA INGRESADA PERTENEZCA A LAS JUGADAS VALIDAS
/*jugadaPosible validarJugada(jugador player[], jugadaPosible jugadasPosibles[]) {
  jugadaPosible failPlay;
  jugadaPosible play;
  
  int x, y;
  bool encontrado = false;

  //si las coordenadas que se ingresan estan en el array de jugadasPosibles, que seria el valor de la casilla vacia, todo OK
  //sino jugada invalida y que vuela a intentarlo
  int topeDeIntentos = 10;
  int i;
  while(!encontrado && topeDeIntentos > 0){
    printf("Ingresa una jugada valida cachito, y mas te vale que sea valida :)\n");
    scanf("%d%d",
      &x,
      &y
    );

    if((x < 0 && x < 9) && (y < 0 && y < 9)){
      for (i = 0; i < 64; i++){
        if(jugadasPosibles[i].coord_fin[0].x == x && jugadasPosibles[i].coord_fin[0].y == y && jugadasPosibles[i].isPlay == true){
          play.coord_inicio.x = jugadasPosibles[i].coord_inicio.x;
          play.coord_inicio.y = jugadasPosibles[i].coord_inicio.y;
          play.coord_fin[0].x = jugadasPosibles[i].coord_fin[0].x;
          play.coord_fin[0].y = jugadasPosibles[i].coord_fin[0].y;
          play.isPlay = true;
          strcpy(play.direccion, jugadasPosibles[i].direccion);
          encontrado = true;
        }
      }

      if(encontrado){
        printf("Felicidades, ingresaste una jugada valida :)\n");
      }else{
        printf("Oops, %d - %d es una casilla invalida cachito :(\n", x, y);
      }
    }else{
      topeDeIntentos--;
    }
  }

  //SI LLEGO AL TOPE DE INTENTOS ES PORQUE EL JUGADOR INGRESO CUALQUIER COSA MENOS UN NUMERO :(
  if(topeDeIntentos <= 0){
    failPlay.coord_inicio.x = -1,
    failPlay.coord_inicio.y = -1,
    failPlay.coord_fin[0].x = -1,
    failPlay.coord_fin[0].y = -1,
    failPlay.isPlay = false,
    strcpy(failPlay.direccion, "none");

    return failPlay;
  }

  //SI LLEGO HASTA ACA EN TEORIA SE INGRESO UNA JUGADA VALIDA, SE DEVUELVE

  return play;
}*/

//INGRESAR UNA JUGADA, Y CAMBIAR LAS FICHAS AFECTADAS EN DICHA JUGADA
//return 1 si salio todo bien | return 0 si salio todo como el culo
int ingresarJugada(tablero* tab, jugadaPosible* play) {
  //ingresar al tablero la jugada del usuario impactando en las fichas que corresponda
  /* Conseguir Coordenada de inicio | coordenada de fin | direccion */
  
  
  /* Actualizar Tablero */



}

void asignarFicha(jugador player[]){//revisar que sea aleatorio realmente
  double valor = (double)rand() / (double)RAND_MAX;
  char resultFicha = (valor >= 0.5) ? 'X' : 'O';

  if(resultFicha == 'X'){
    player[0].ficha = 'X';
    player[1].ficha = 'O';
  }else{
    player[0].ficha = 'O';
    player[1].ficha = 'X';
  }
}

//INICIAR TABLERO
void iniciarTablero(tablero* tab){
  int id = 0;
  // Inciar el tablero con todas las posiciones en '_'
  for (int j = 1; j <= 8; j++) {
      for (int k = 1; k <= 8; k++) {
          tab->jugada[id].x = j;
          tab->jugada[id].y = k;
          tab->jugada[id].ficha = '_';
          tab->jugada[id].empty = true;
          id++;
      }
  }

  //colocar fichas en la posicion inicial

  tab->jugada[26].x = 4;
  tab->jugada[26].y = 3;
  tab->jugada[26].ficha = 'X';
  tab->jugada[26].empty = false;
  
  tab->jugada[27].x = 4;
  tab->jugada[27].y = 4;
  tab->jugada[27].ficha = 'X';
  tab->jugada[27].empty = false;

  tab->jugada[28].x = 4;
  tab->jugada[28].y = 5;
  tab->jugada[28].ficha = 'X';
  tab->jugada[28].empty = false;
  
  tab->jugada[34].x = 5;
  tab->jugada[34].y = 3;
  tab->jugada[34].ficha = 'O';
  tab->jugada[34].empty = false;
  
  tab->jugada[35].x = 5;
  tab->jugada[35].y = 4;
  tab->jugada[35].ficha = 'O';
  tab->jugada[35].empty = false;

  tab->jugada[36].x = 5;
  tab->jugada[36].y = 5;
  tab->jugada[36].ficha = 'O';
  tab->jugada[36].empty = false;
}

//Enumera las jugadas validas para todas las fichas del jugador actual
void posicionFichas(jugador* player, tablero* tab, jugadaPosible play[]){
  for (int i = 0; i < 64; i++)
  {
    //busca las casillas que tengan la ficha del jugador actual y llama a findplay para cada ficha encontrada
    if(tab->jugada[i].ficha == player->ficha){
        findPlay(player, tab, tab->jugada[i].x, tab->jugada[i].y, play); 
    }
  }
}

//CREAR JUGADORES
void crearJugador(jugador player[], int tope) {
  for(int i = 0; i < tope; i++){
    printf("Ingrese los datos de los jugadores\n");
    printf("Jugador %d\n", i + 1);
    printf("Nombre: ");
    scanf("%s", player[i].nombre);
    asignarFicha(player);
    player[i].turno = 0;
    player[i].id = i;
    printf("\n");
  }
}

jugador actualizarTurno(jugador player[]){
  if(player[0].turno == 0 && player[1].turno == 0){//primer movimiento
    if(player[0].ficha == 'X'){
      player[0].turno++;
      player[0].ultimoTurno = true;
      return player[0];
    }else{
      player[1].turno++;
      player[1].ultimoTurno = true;
      return player[1];
    }
  }else{//siguientes movimientos
    if(player[0].ultimoTurno == true){
      player[1].turno++; //el player 0 fue el ultimo
      player[1].ultimoTurno = true;
      player[0].ultimoTurno = false;
      return player[1];
    }else{
      player[0].turno++; //el player 1 fue el ultimo
      player[0].ultimoTurno = true;
      player[1].ultimoTurno = false;
      return player[0];
    }
  }
}
//codigo en el HP NO TE OLVIDES!!!------------------------------------------------------------------------------

// RENDERIZAR EL TABLERO Y LA POSICION DE LAS FICHAS
void renderTablero(tablero* tab){
  int turno = 0;
  int coordIndexP2 = 0;
  char message[30];
  bool ficha;

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      //verticales
      if(j == 0 || j == 9){
        if(i > 0 && i < 9){
          printf(" %d ", i);//numeros verticales
        }else{
          printf(" - ");//esquinas del tablero
        }
      //horizontales
      }else if(i == 0 || i == 9){
        printf(" %d ", j);//numeros horizontales
      }else{
        //loop para buscar y renderizar las fichitas
        for (int k = 0; k < 64; k++) {
            if (i == tab->jugada[k].x && j == tab->jugada[k].y) {
                printf(" %c ", tab->jugada[k].ficha);
            }
        }
      }
    }
    printf("\n");
  }
}

//MOSTRAR INFO DE TURNO, ETC.
void showInfo(jugador player[]){
  printf("%s  %d Ficha: %c | Turno actual: %d\n", 
    player[0].nombre, 
    player[0].id, 
    player[0].ficha, 
    player[0].turno
  );

  printf("%s  %d Ficha: %c | Turno actual: %d\n", 
    player[1].nombre, 
    player[1].id, 
    player[1].ficha, 
    player[1].turno
  );

  printf("\n\n");
}

//FUNCION PARA CONTAR FICHAS EN TABLERO??

// MAIN ************************************************************************************************
int main() {
  jugador jugadores[2];
  tablero tab;
  jugadaPosible play[64];
  coordenada test;

  iniciarPlays(play);

  srand(time(NULL));

  crearJugador(jugadores, 2);

  iniciarTablero(&tab);

  jugador player = actualizarTurno(jugadores);
  
  //HACE UN BARRIDO DE TODAS LAS FICHAS DEL JUGADOR ACTUAL Y BUSCA SUS JUGADAS VALIDAS
  posicionFichas(&player, &tab, play);

  //MUESTRA LAS JUGADAS VALIDAS (FALTA RESETEARLAS PARA ORTO TURNO)
  showPlays(play); 

  renderTablero(&tab);

  // validarJugada(&player, play);

  showInfo(jugadores);
} 



//BORRAR DESPUES
/*
//MOVIMIENTOS POSIBLES
void movimientosPosible(jugador player[], tablero* tab) {
  /*
  si ficha igual entonces
  EJ: cordenada 4-4 -> buscar en las coordenadas adyacentes (8 coordenadas)
  * Horizontales: [4-3]Hl [4-5]Hr
  * Verticales: [3-4]Vt [5-4]Vb
  * Diagonales: [3-3]Dtl [3-5]Dtr [5-3]Dbl [5-5]Dbr */
  
  //si hay ficha del contrario, revisar siguiente ficha en esa misma direccion (Hor Vert Diag)
  //  si sigue habiendo fichas de contrario seguir hasta que:
  //  jugada invalida: hay una ficha del jugador actual en la siguiente casilla o el fin del tablero
  //  jugada valida: hay un espacio vacio:
      //-> si hay espacio vacio guardar la coordenada de ese espacio vacio, mas la direccion (Hor, Vert, Diag)
      // y devolver al sistema la posible jugada con
      // - coordenada de la ficha principal
      // - coordenada del espacio vacio
      // - direccion (Hor, Vert, Diag)

  //por ultimo pasar esto a la funcion validar jugada para que le pida al usuario alguna de las jugadas validas
 /* coordenada jugada_posible[60];
  char ficha_a_buscar = player[1].ficha;
  char ficha_oponente = player[0].ficha;
  bool ficha;
  
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      /* buscar ficha igual a la del jugador actual */
    /*  for (int k = 0; k < 64; k++){
        if (i == tab->jugada[k].x && j == tab->jugada[k].y && tab->jugada[k].ficha == ficha_a_buscar){
          printf("coordenadas con %c: %d - %d\n", tab->jugada[k].ficha, tab->jugada[k].x, tab->jugada[k].y);  
          int search = 0;
          while(search < 64){
            if(tab->jugada[search].x == tab->jugada[k].x - 1 
            && tab->jugada[search].y == tab->jugada[k].y - 1 
            && tab->jugada[search].ficha == ficha_oponente){
              printf("Encontrada diagonal superior izquierda en... %d - %d | %c\n", 
              tab->jugada[search].x, 
              tab->jugada[search].y, 
              tab->jugada[search].ficha);
            }
            search++;
          }
          search = 0;
          while(search < 64){
            if(tab->jugada[search].x == tab->jugada[k].x - 1
            && tab->jugada[search].y == tab->jugada[k].y 
            && tab->jugada[search].ficha == ficha_oponente){
              printf("Encontrada vertical superior en... %d - %d | %c\n", 
              tab->jugada[search].x, 
              tab->jugada[search].y, 
              tab->jugada[search].ficha);
              int i = 0;
              while(i < 64){
                if(tab->jugada[i].x == tab->jugada[search].x - 1
                && tab->jugada[i].y == tab->jugada[search].y){
                  printf("Jugada posible en: %d %d | %c\n", tab->jugada[i].x, tab->jugada[i].y, tab->jugada[i].ficha);
                }
                i++;
              }
            }
            search++;
          }
          search = 0;
          while(search < 64){
            if(tab->jugada[search].x == tab->jugada[k].x - 1 
            && tab->jugada[search].y == tab->jugada[k].y + 1 
            && tab->jugada[search].ficha == ficha_oponente){
              printf("Encontrada diagonal superior derecha en... %d - %d | %c\n", 
              tab->jugada[search].x, 
              tab->jugada[search].y, 
              tab->jugada[search].ficha);
            }
            search++;
          }
          search = 0;
          while(search < 64){
            if(tab->jugada[search].x == tab->jugada[k].x
            && tab->jugada[search].y == tab->jugada[k].y - 1
            && tab->jugada[search].ficha == ficha_oponente){
              printf("Encontrada horizontal izquierda en... %d - %d | %c\n",
              tab->jugada[search].x,
              tab->jugada[search].y,
              tab->jugada[search].ficha);
              int i = 0;
              while(i < 64){
                if(tab->jugada[i].x == tab->jugada[search].x
                && tab->jugada[i].y == tab->jugada[search].y - 1){
                  printf("Jugada posible en: %d %d | %c\n", tab->jugada[i].x, tab->jugada[i].y, tab->jugada[i].ficha);
                }
                i++;
              }
            }
            search++;
          }
          search = 0;
          while(search < 64){
            if(tab->jugada[search].x == tab->jugada[k].x 
            && tab->jugada[search].y == tab->jugada[k].y + 1 
            && tab->jugada[search].ficha == ficha_oponente){
              printf("Encontrada horizontal derecha en... %d - %d | %c\n", 
              tab->jugada[search].x, 
              tab->jugada[search].y, 
              tab->jugada[search].ficha);
              int i = 0;
              while(i < 64){
                if(tab->jugada[i].x == tab->jugada[search].x
                && tab->jugada[i].y == tab->jugada[search].y + 1){
                  printf("Jugada posible en: %d %d | %c\n", tab->jugada[i].x, tab->jugada[i].y, tab->jugada[i].ficha);
                }
                i++;
              }
            }
            search++;
          }
          search = 0;
          while(search < 64){
            if(tab->jugada[search].x == tab->jugada[k].x + 1 
            && tab->jugada[search].y == tab->jugada[k].y - 1 
            && tab->jugada[search].ficha == ficha_oponente){
              printf("Encontrada diagonal inferior derecha en... %d - %d | %c\n", 
              tab->jugada[search].x, 
              tab->jugada[search].y, 
              tab->jugada[search].ficha);
            }
            search++;
          }
          search = 0;
          while(search < 64){
            if(tab->jugada[search].x == tab->jugada[k].x + 1 
            && tab->jugada[search].y == tab->jugada[k].y 
            && tab->jugada[search].ficha == ficha_oponente){
              printf("Encontrada vertical inferior en... %d - %d | %c\n", 
              tab->jugada[search].x, 
              tab->jugada[search].y, 
              tab->jugada[search].ficha);
              int i = 0;
              while(i < 64){
                if(tab->jugada[i].x == tab->jugada[search].x + 1
                && tab->jugada[i].y == tab->jugada[search].y){
                  printf("Jugada posible en: %d %d | %c\n", tab->jugada[i].x, tab->jugada[i].y, tab->jugada[i].ficha);
                }
                i++;
              }
            }
            search++;
          }
          search = 0;
          while(search < 64){
            if(tab->jugada[search].x == tab->jugada[k].x + 1 
            && tab->jugada[search].y == tab->jugada[k].y + 1 
            && tab->jugada[search].ficha == ficha_oponente){
              printf("Encontrada diagonal inferior derecha en... %d - %d | %c\n", 
              tab->jugada[search].x , 
              tab->jugada[search].y, 
              tab->jugada[search].ficha);
            }
            search++;
          }
      }
    }
  }

  // printf("Coordenadas validas: -- -- -- -- ");
  //guardarlo en el array de jugadas posibles
  //EJEMPLO: para las O [4-4] las jugadas posibles son [6-4]Vb [4-6]Hr
  //EJEMPLO: para las O [5-5] las jugadas posibles son [5-3]Hl [3-5]Vt
  //el usuario debe ingresar estas coordenadas ( [6-4] [4-6] [5-3] [3-5] ) 
  //cualquiera coordenada fuera de estas NO es valida
  printf("\n");
}
}*/