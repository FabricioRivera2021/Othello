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
  int x;
  int y;
} playDelUsuario;

typedef struct {
  char direccion[20];
} play_direccions;

typedef struct {
  coordenada coord_inicio;
  coordenada coord_fin[3];//a lo sumo 3 coordenadas al mismo tiempo
  play_direccions play_direccion[3];
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

//ACTUALIZAR FICHAS DEPENDIENDO DEL ID Y DE LA FICHA ACTUAL DE LA JUGADA
void updateFicha(tablero* tab, int id) {

  tab->jugada[id].ficha = 'X';
}

//si hay mas de una direccion, obtener las coordenadas de esos origenes
// coordenada getOrigenExtra(coordenada* cord, jugadaPosible plays[]) {
//   for (int i = 0; i < 64; i++){
//     play
//   }
  
// }

//obtener la direccion para una coordenada de jugada en concreto
play_direccions getDireccion (jugadaPosible* play, jugadaPosible plays[]) {
  play_direccions direcciones[3];



  return *direcciones;
}

//devuelve la coordenada a partir de una id de casilla
/*coordenada getCoordenada (tablero* tab, int id) {
  coordenada coord;

  coord.ficha = '!';
  coord.empty = false;

  int ident = 0;
  for (int j = 1; j <= 8; j++) {
    for (int k = 1; k <= 8; k++) {
      if(ident == id){
        coord.x = j;
        coord.y = k;
        return coord;
      }
      ident++;
    }
  }
}*/

// getIdCasilla(tab, plays[i].coord_inicio.x, plays[i].coord_inicio.y);
//devuelve el id de la casilla para una coordenada en concreto
int getIdCasilla (tablero* tab, int x, int y) {
  int id = 0;
  for (int j = 1; j <= 8; j++) {
    for (int k = 1; k <= 8; k++) {
      if(tab->jugada[id].x == x && tab->jugada[id].y == y){
        return id;
      }
      id++;
    }
  }
}

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
      strcpy(plays[i].play_direccion[0].direccion, "none");
      strcpy(plays[i].play_direccion[1].direccion, "none");
      strcpy(plays[i].play_direccion[2].direccion, "none");
      plays[i].isPlay = false;
  }
}

void showPlays (jugadaPosible plays[]){
  for(int i = 0; i < 64; i++){
    // si tiene 3 jugadas
    if(plays[i].isPlay == 1 && plays[i].coord_fin[0].x != 0 && plays[i].coord_fin[1].x != 0 && plays[i].coord_fin[2].x != 0){
      printf("\n-jugada valida en---------------------\n [%d - %d]  ----------------------------\njugada1|%d - %d| direccion: %s\njugada2|%d - %d| direccion: %s\njugada3|%d - %d| direccion: %s\n", 
        // i,
        plays[i].coord_inicio.x,
        plays[i].coord_inicio.y,
        plays[i].coord_fin[0].x,
        plays[i].coord_fin[0].y,
        plays[i].play_direccion[0].direccion,
        plays[i].coord_fin[1].x,
        plays[i].coord_fin[1].y,
        plays[i].play_direccion[1].direccion,
        plays[i].coord_fin[2].x,
        plays[i].coord_fin[2].y,
        plays[i].play_direccion[2].direccion
      );
    //tiene 2 jugadas
    }else if(plays[i].isPlay == 1 && plays[i].coord_fin[0].x != 0 && plays[i].coord_fin[1].x != 0 && plays[i].coord_fin[2].x == 0){
        printf("\n-jugada valida en---------------------\n [%d - %d]  ----------------------------\njugada1|%d - %d| direccion: %s\njugada2|%d - %d| direccion: %s\n", 
        // i,
        plays[i].coord_inicio.x,
        plays[i].coord_inicio.y,
        plays[i].coord_fin[0].x,
        plays[i].coord_fin[0].y,
        plays[i].play_direccion[0].direccion,
        plays[i].coord_fin[1].x,
        plays[i].coord_fin[1].y,
        plays[i].play_direccion[1].direccion
      );
      //tiene 1 jugada
    }else if(plays[i].isPlay == 1 && plays[i].coord_fin[0].x != 0 && plays[i].coord_fin[1].x == 0 && plays[i].coord_fin[2].x == 0){
        printf("\n-jugada valida en---------------------\n [%d - %d]  ----------------------------\njugada1|%d - %d| direccion: %s\n", 
        // i,
        plays[i].coord_inicio.x,
        plays[i].coord_inicio.y,
        plays[i].coord_fin[0].x,
        plays[i].coord_fin[0].y,
        plays[i].play_direccion[0].direccion
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
      strcpy(plays[i].play_direccion[0].direccion, direccion);
      plays[i].isPlay = 1;
      // strcpy(plays[i].direccion, direccion);
      break;
    //quiere decir que para ese valor de origen existen mas direcciones de jugadas posibles
    }
    else if(plays[i].coord_inicio.x == x && plays[i].coord_inicio.y == y){
      if(plays[i].coord_fin[1].x == 0 && plays[i].coord_fin[1].y == 0){
        plays[i].coord_fin[1].x = fin_x;
        plays[i].coord_fin[1].y = fin_y;
        strcpy(plays[i].play_direccion[1].direccion, direccion);
        break;
      }else{
        plays[i].coord_fin[2].x = fin_x;
        plays[i].coord_fin[2].y = fin_y;
        strcpy(plays[i].play_direccion[2].direccion, direccion);
        break;
      }
    }
  }
}

void obtenerIdDeCasillasAfectadas(int* count2, int resultado[], tablero* tab, char* direccion1, char* direccion2, char* direccion3, int origen_x,int origen_y,int fin_x,int fin_y){

  *count2 = 0;
  int x, y;

  if (strcmp(direccion1, "diag_sup_izq") == 0
      ||strcmp(direccion2, "diag_sup_izq") == 0
      ||strcmp(direccion3, "diag_sup_izq") == 0) {
      x = -1; y = -1;
  } else if (strcmp(direccion1, "vertical+") == 0
              ||strcmp(direccion2, "vertical+") == 0
              ||strcmp(direccion3, "vertical+") == 0) {
      x = -1; y = 0;
  } else if (strcmp(direccion1, "diag_sup_der") == 0
              ||strcmp(direccion2, "diag_sup_der") == 0
              ||strcmp(direccion3, "diag_sup_der") == 0) {
      x = -1; y = 1;
  } else if (strcmp(direccion1, "horizontal-") == 0
              ||strcmp(direccion2, "horizontal-") == 0
              ||strcmp(direccion3, "horizontal-") == 0) {
      x = 0; y = -1;
  } else if (strcmp(direccion1, "horizontal+") == 0
              ||strcmp(direccion2, "horizontal+") == 0
              ||strcmp(direccion3, "horizontal+") == 0) {
      x = 0; y = 1;
  } else if (strcmp(direccion1, "diag_inf_izq") == 0
              ||strcmp(direccion2, "diag_inf_izq") == 0
              ||strcmp(direccion3, "diag_inf_izq") == 0) {
      x = 1; y = -1;
  } else if (strcmp(direccion1, "vertical-") == 0
              ||strcmp(direccion2, "vertical-") == 0
              ||strcmp(direccion3, "vertical-") == 0) {
      x = 1; y = 0;
  } else if (strcmp(direccion1, "diag_inf_der") == 0
              ||strcmp(direccion2, "diag_inf_der") == 0
              ||strcmp(direccion3, "diag_inf_der") == 0) {
      x = 1; y = 1;
  }

  //mientras la coordenada de origen no sea la coordenada de final hacer el coso coso de las x e y
  while (origen_x != fin_x || origen_y != fin_y){
   printf("1 origen.> %d - %d final-> %d - %d\n", origen_x, origen_y, fin_x, fin_y);
   resultado[*count2] = getIdCasilla(tab, origen_x, origen_y);
   origen_x += x;
   origen_y += y;
   (*count2)++;
   }
  resultado[*count2] = getIdCasilla(tab, origen_x, origen_y);
  origen_x += x;
  origen_y += y;
  (*count2)++;
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
      find(tab, result.x, result.y, 1, player->ficha, ficha_oponente, plays);
    }
    //arriba
    if (tab->jugada[j].x == result.x - 1 && tab->jugada[j].y == result.y && tab->jugada[j].ficha == ficha_oponente){
      find(tab, result.x, result.y, 2, player->ficha, ficha_oponente, plays);
    }
    //diagonal sup der
    if (tab->jugada[j].x == result.x - 1 && tab->jugada[j].y == result.y + 1 && tab->jugada[j].ficha == ficha_oponente){
      find(tab, result.x, result.y, 3, player->ficha, ficha_oponente, plays);
    }
    //derecha 
    if (tab->jugada[j].x == result.x && tab->jugada[j].y == result.y + 1 && tab->jugada[j].ficha == ficha_oponente){
      find(tab, result.x, result.y, 5, player->ficha, ficha_oponente, plays);
    }
    //izquierda
    if (tab->jugada[j].x == result.x && tab->jugada[j].y == result.y - 1 && tab->jugada[j].ficha == ficha_oponente){
      find(tab, result.x, result.y, 4, player->ficha, ficha_oponente, plays);
    }
    //diagonal inf izq -- --
    if (tab->jugada[j].x == result.x + 1 && tab->jugada[j].y == result.y - 1 && tab->jugada[j].ficha == ficha_oponente){
      find(tab, result.x, result.y, 6, player->ficha, ficha_oponente, plays);
    }
    //abajo -- -- --
    if (tab->jugada[j].x == result.x + 1 && tab->jugada[j].y == result.y && tab->jugada[j].ficha == ficha_oponente){
      find(tab, result.x, result.y, 7, player->ficha, ficha_oponente, plays);
    }
    //diagonal inf der -- --
    if (tab->jugada[j].x == result.x + 1 && tab->jugada[j].y == result.y + 1 && tab->jugada[j].ficha == ficha_oponente){
      find(tab, result.x, result.y, 8, player->ficha, ficha_oponente, plays);
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

//VALIDAR QUE LA JUGADA INGRESADA PERTENEZCA A LAS JUGADAS VALIDAS
//RETORNA EL VALOR DE LA COORDENADA DE ORIGEN
jugadaPosible validarJugada(jugador player[], jugadaPosible jugadasPosibles[]) {
  jugadaPosible play;
  int x, y;
  bool encontrado = false;

  //si las coordenadas que se ingresan estan en el array de jugadasPosibles, que seria el valor de la casilla vacia, todo OK
  //sino jugada invalida y que vuela a intentarlo

  int topeDeIntentos = 5;
  int i;
  while(!encontrado && topeDeIntentos > 0){
    if(player[0].ultimoTurno == true){
      printf("Turno de: %s\n", player[0].nombre);
    }else{
      printf("Turno de: %s\n", player[1].nombre);
    }

    printf("Ingresa una jugada...\n");
    scanf("%d%d",
      &x,
      &y
    );
    
    if((x > 0 && x < 9) && (y > 0 && y < 9)){
      for (i = 0; i < 64; i++){
        if(jugadasPosibles[i].coord_fin[0].x == x && jugadasPosibles[i].coord_fin[0].y == y && jugadasPosibles[i].isPlay == true) {
          play.coord_inicio.x = jugadasPosibles[i].coord_inicio.x;
          play.coord_inicio.y = jugadasPosibles[i].coord_inicio.y;
          play.coord_fin[0].x = jugadasPosibles[i].coord_fin[0].x;
          play.coord_fin[0].y = jugadasPosibles[i].coord_fin[0].y;
          strcpy(play.play_direccion[0].direccion, jugadasPosibles[i].play_direccion[0].direccion);
          encontrado = true;
        }
        else if(jugadasPosibles[i].coord_fin[1].x == x && jugadasPosibles[i].coord_fin[1].y == y && jugadasPosibles[i].isPlay == true) {
          play.coord_inicio.x = jugadasPosibles[i].coord_inicio.x;
          play.coord_inicio.y = jugadasPosibles[i].coord_inicio.y;
          play.coord_fin[0].x = jugadasPosibles[i].coord_fin[1].x;
          play.coord_fin[0].y = jugadasPosibles[i].coord_fin[1].y;
          strcpy(play.play_direccion[1].direccion, jugadasPosibles[i].play_direccion[1].direccion);
          encontrado = true;
        }
        else if(jugadasPosibles[i].coord_fin[2].x == x && jugadasPosibles[i].coord_fin[2].y == y && jugadasPosibles[i].isPlay == true) {
          play.coord_inicio.x = jugadasPosibles[i].coord_inicio.x;
          play.coord_inicio.y = jugadasPosibles[i].coord_inicio.y;
          play.coord_fin[0].x = jugadasPosibles[i].coord_fin[2].x;
          play.coord_fin[0].y = jugadasPosibles[i].coord_fin[2].y;
          strcpy(play.play_direccion[2].direccion, jugadasPosibles[i].play_direccion[2].direccion);
          encontrado = true;
        }
      }

      if(encontrado){
        printf("Felicidades, ingresaste una jugada valida :)\n\n");
      }else{
        printf("Oops, %d - %d es una casilla invalida :(\n\n", x, y);
      }
      
    }else{
      topeDeIntentos--;
      break;
    }
  }

  //SI LLEGO AL TOPE DE INTENTOS ES PORQUE EL JUGADOR INGRESO CUALQUIER COSA MENOS UN NUMERO :(
  //y el programa crashea!!
  if(topeDeIntentos <= 0){
    printf("Error, saliendo del progama... se ingreso algo que no era un numero\n");
  }

  //SI LLEGO HASTA ACA EN TEORIA SE INGRESO UNA JUGADA VALIDA, SE DEVUELVE la coordenada original de la ficha
  return play;
}

//INGRESAR UNA JUGADA, Y CAMBIAR LAS FICHAS AFECTADAS EN DICHA JUGADA return 1 si OK | return 0 si MAL
int ingresarJugada(tablero* tab, jugadaPosible* jugada, jugadaPosible plays[]) {
  coordenada inicio[3];
  //HARDCODEADO POR AHORA
  char ficha_a_insertar = 'X';
  int id[3] = {0};
  // SI las coordenadas de final tienen mas de un origen hay que afectar mas de una direccion, sino... 1 sola direccion

  //conseguir coordenadas de fin de la jugada del usuario
  //AL SER UNA COORDENADA LA QUE INGRESA EN USUARIO VIENE SIEMPRE EN EL INDEX 0 -> jugada->coord_fin[0]
  int count = 0;
  for (int j = 0; j < 3 ; j++){
    for (int i = 0; i < 64; i++){
      if(jugada->coord_fin[0].x == plays[i].coord_fin[0].x && jugada->coord_fin[0].y == plays[i].coord_fin[0].y){
        //get plays->coord_inicio.x and plays->coord_inicio.y
        id[count] = getIdCasilla(tab, plays[i].coord_inicio.x, plays[i].coord_inicio.y);
        inicio[count].x = plays[i].coord_inicio.x;
        inicio[count].y = plays[i].coord_inicio.y;
        count++;
        break;
      }else if(jugada->coord_fin[0].x == plays[i].coord_fin[1].x && jugada->coord_fin[0].y == plays[i].coord_fin[1].y){
        id[count] = getIdCasilla(tab, plays[i].coord_inicio.x, plays[i].coord_inicio.y);
        inicio[count].x = plays[i].coord_inicio.x;
        inicio[count].y = plays[i].coord_inicio.y;
        count++;
        break;
      }else if(jugada->coord_fin[0].x == plays[i].coord_fin[2].x && jugada->coord_fin[0].y == plays[i].coord_fin[2].y){
        id[count] = getIdCasilla(tab, plays[i].coord_inicio.x, plays[i].coord_inicio.y);
        inicio[count].x = plays[i].coord_inicio.x;
        inicio[count].y = plays[i].coord_inicio.y;
        count++;
        break;
      }
    }
  }
  
  for (int i = 0; i < count; i++){//count es la cantidad de direcciones que afecta la jugada
    printf("LINEA 591 id de casilla %d\n", id[i]);
    printf("LINEA 592 ORIGEN: [%d - %d]\nDireccion 1|%s| 2|%s| 3|%s|\n", 
      inicio[i].x, 
      inicio[i].y, 
      jugada->play_direccion[0].direccion, 
      jugada->play_direccion[1].direccion,
      jugada->play_direccion[2].direccion);
  }

  //1 direccion | if count == 0
  int casillasID[8] = { 0 };
  int count2 = 0; //dependiendo de la cantidad de direcciones que hallan
  int origen_x = jugada->coord_inicio.x;
  int origen_y = jugada->coord_inicio.y;

  if(count == 1){
    obtenerIdDeCasillasAfectadas(
      &count2,
      casillasID,
      tab, 
      jugada->play_direccion[0].direccion,
      jugada->play_direccion[1].direccion,
      jugada->play_direccion[2].direccion,
      origen_x,
      origen_y,
      jugada->coord_fin[0].x,
      jugada->coord_fin[0].y
    );

    for (int i = 0; i < count2; i++){
      updateFicha(tab, casillasID[i]); //actualizar el tablero
      printf("%d\n", casillasID[i]);
    }
  }

  //2 direcciones | if count == 1
  /*if(count == 2){
    for (int i = 0; i < 2; i++){
      obtenerIdDeCasillasAfectadas(
        &count2,
        casillasID,
        tab,
        jugada->play_direccion[0].direccion,
        jugada->play_direccion[1].direccion,
        jugada->play_direccion[2].direccion,
        inicio[i].x,
        inicio[i].y,
        jugada->coord_fin[0].x,
        jugada->coord_fin[0].y
      );

      for (int i = 0; i < count2; i++){
        updateFicha(tab, casillasID[i]); //actualizar el tablero
        printf("%d\n", casillasID[i]);
      }
    }
  }*/


  
  //3 direcciones !!!



  return 1;
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

  printf("\n");
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

  jugadaPosible jugada = validarJugada(&player, play);

  // printf("Se ingreo una jugada para la ficha X en [%d - %d]\n", jugada.coord_fin[0].x, jugada.coord_fin[0].y);

  int result = ingresarJugada(&tab, &jugada, play);
  // printf("%d", result);

  renderTablero(&tab);
  
  showInfo(jugadores);


  printf("fin de ejecucion");
} 

/* FUNCION EN PROGRESO
int obtenerIdDeCasillasAfectadas(direccion1, direccion2, direccion3, direccionObjetivo){
	int result[8];
	int count = 0;
	int x, y;
	direccionObjetivo = "diag_sup_izq" -> x = -1 | y = -1 
	direccionObjetivo = "diag_sup_izq" -> x = -1 | y = 0 
	direccionObjetivo = "diag_sup_izq" -> x = -1 | y = +1 
	direccionObjetivo = "diag_sup_izq" -> x = 0 | y = -1 
	direccionObjetivo = "diag_sup_izq" -> x = 0 | y = +1 
	direccionObjetivo = "diag_sup_izq" -> x = +1 | y = -1 
	direccionObjetivo = "diag_sup_izq" -> x = +1 | y = 0
	direccionObjetivo = "diag_sup_izq" -> x = +1 | y = +1

   if(strcmp(direccion1, direccionObjetivo) == 0
      ||strcmp(direccion2, direccionObjetivo)  == 0
      ||strcmp(direccion3, direccionObjetivo)  == 0){
      //mientras la coordenada de origen no sea la coordenada de final hacer el coso coso de las x e y
      while (origen_x != jugada->coord_fin[0].x && origen_y != jugada->coord_fin[0].y){
        printf("1 origen.> %d - %d final-> %d - %d\n", origen_x, origen_y, jugada->coord_fin[0].x, jugada->coord_fin[0].y);
        casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
        origen_x += x;
        origen_y += y;
        count++;
      }
      casillasID[count] = getIdCasilla(tab, origen_x, origen_y);
      origen_x += x;
      origen_y += y;
      count++;
}
*/


/*
    if(strcmp(jugada->play_direccion[0].direccion, "diag_sup_izq") == 0
      ||strcmp(jugada->play_direccion[1].direccion, "diag_sup_der")  == 0
      ||strcmp(jugada->play_direccion[2].direccion, "diag_sup_der")  == 0){
      //mientras la coordenada de origen no sea la coordenada de final hacer el coso coso de las x e y
      //-1 -1
      while (origen_x != jugada->coord_fin[0].x && origen_y != jugada->coord_fin[0].y){
        printf("1 origen.> %d - %d final-> %d - %d\n", origen_x, origen_y, jugada->coord_fin[0].x, jugada->coord_fin[0].y);
        casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
        origen_x--;
        origen_y--;
        count2++;
      }
      casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
      origen_x--;
      origen_y--;
      count2++;
    }else if(strcmp(jugada->play_direccion[0].direccion, "vertical+")  == 0
            ||strcmp(jugada->play_direccion[1].direccion, "diag_sup_der")  == 0
            ||strcmp(jugada->play_direccion[2].direccion, "diag_sup_der")  == 0){
      //-1 0
      while (origen_x != jugada->coord_fin[0].x && origen_y != jugada->coord_fin[0].y){
        printf("2 origen.> %d - %d final-> %d - %d\n", origen_x, origen_y, jugada->coord_fin[0].x, jugada->coord_fin[0].y);
        casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
        origen_x--;
        count2++;
      }
      casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
      origen_x--;
      count2++;
    }else if(strcmp(jugada->play_direccion[0].direccion, "diag_sup_der")  == 0
            ||strcmp(jugada->play_direccion[1].direccion, "diag_sup_der")  == 0
            ||strcmp(jugada->play_direccion[2].direccion, "diag_sup_der")  == 0){
      //-1 +1
      while (origen_x != jugada->coord_fin[0].x && origen_y != jugada->coord_fin[0].y){
        printf("3 origen.> %d - %d final-> %d - %d\n", origen_x, origen_y, jugada->coord_fin[0].x, jugada->coord_fin[0].y);
        casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
        origen_x--;
        origen_y++;
        count2++;
      }
      casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
      origen_x--;
      origen_y++;
      count2++;
    }else if(strcmp(jugada->play_direccion[0].direccion, "horizontal-")  == 0
            ||strcmp(jugada->play_direccion[1].direccion, "horizontal-")  == 0
            ||strcmp(jugada->play_direccion[2].direccion, "horizontal-")  == 0){
      //0 -1
      while (origen_x != jugada->coord_fin[0].x || origen_y != jugada->coord_fin[0].y){
        printf("4 origen.> %d - %d final-> %d - %d\n", origen_x, origen_y, jugada->coord_fin[0].x, jugada->coord_fin[0].y);
        casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
        origen_y--;
        count2++;
      }
      casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
      origen_y--;
      count2++;
    }else if(strcmp(jugada->play_direccion[0].direccion, "horizontal+")  == 0
            ||strcmp(jugada->play_direccion[1].direccion, "horizontal+")  == 0
            ||strcmp(jugada->play_direccion[2].direccion, "horizontal+")  == 0){
      //0 +1
      while (origen_x != jugada->coord_fin[0].x || origen_y != jugada->coord_fin[0].y){
        printf("5 origen.> %d - %d final-> %d - %d\n", origen_x, origen_y, jugada->coord_fin[0].x, jugada->coord_fin[0].y);
        casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
        origen_y++;
        count2++;
      }
      casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
      origen_y++;
      count2++;
    }else if(strcmp(jugada->play_direccion[0].direccion, "diag_inf_izq") == 0
            ||strcmp(jugada->play_direccion[1].direccion, "diag_inf_izq") == 0
            ||strcmp(jugada->play_direccion[2].direccion, "diag_inf_izq") == 0){
      //+1 -1
      while (origen_x != jugada->coord_fin[0].x && origen_y != jugada->coord_fin[0].y){
        printf("6 origen.> %d - %d final-> %d - %d\n", origen_x, origen_y, jugada->coord_fin[0].x, jugada->coord_fin[0].y);
        casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
        origen_x++;
        origen_y--;
        count2++;
      }
      casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
      origen_x++;
      origen_y--;
      count2++;
    }else if(strcmp(jugada->play_direccion[0].direccion, "vertical-") == 0
            ||strcmp(jugada->play_direccion[1].direccion, "vertical-") == 0
            ||strcmp(jugada->play_direccion[2].direccion, "vertical-") == 0){
      //+1 0
      while (origen_x != jugada->coord_fin[0].x || origen_y != jugada->coord_fin[0].y){
        printf("7 origen.> %d - %d final-> %d - %d\n", origen_x, origen_y, jugada->coord_fin[0].x, jugada->coord_fin[0].y);
        casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
        origen_x++;
        count2++;
      }
      casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
      origen_x++;
      count2++;
    }else if(strcmp(jugada->play_direccion[0].direccion, "diag_inf_der")  == 0
            ||strcmp(jugada->play_direccion[1].direccion, "diag_inf_der")  == 0
            ||strcmp(jugada->play_direccion[2].direccion, "diag_inf_der")  == 0){
      //+1 +1
      while (origen_x != jugada->coord_fin[0].x && origen_y != jugada->coord_fin[0].y){
        printf("8 origen.> %d - %d final-> %d - %d\n", origen_x, origen_y, jugada->coord_fin[0].x, jugada->coord_fin[0].y);
        casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
        origen_x++;
        origen_y++;
        count2++;
      }
      casillasID[count2] = getIdCasilla(tab, origen_x, origen_y);
      origen_x++;
      origen_y++;
      count2++;
    }
    */