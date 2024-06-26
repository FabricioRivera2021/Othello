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
  coordenada coord_fin[8];
  play_direccions play_direccion[8];
  bool isPlay;
} jugadaPosible;

typedef struct {
  coordenada jugada[64];
  int coordenada_id; //id de la casilla "64" casillas posibles
} tablero;

typedef struct {
  char nombre[60]; 
  char ficha; //ficha que este usando el jugador
  int turno; //contador de turnos
  bool turnoActual; //para saber quien tuvo el ultimo turno
} jugador;

void mensajeFinal(int blancas, int negras){
    if(negras > blancas){
      printf("Ganan las fichas negras.. con %d en el tablero contra %d fichas blancas\n", negras, blancas);
    }else if(negras < blancas){
      printf("Ganan las fichas blancas.. con %d en el tablero contra %d fichas negras\n", blancas, negras);
    }else if(negras == blancas){
      printf("Empate....  - negras: %d blancas: %d\n", negras, blancas);
    }
}

int contarFichas(tablero* tab, char ficha){
  int count = 0;
  for (int i = 0; i < 64; i++){
    if(tab->jugada[i].ficha == ficha){
      count++;
    }
  }
  return count;
}

int chckearSiHayJugadas(jugadaPosible plays[]){
  for (int i = 0; i < 64; i++){
    if(plays[i].isPlay){
      return 1;
      break;
    }
  }
  return 0;
}

//ACTUALIZAR FICHAS DEPENDIENDO DEL ID Y DE LA FICHA ACTUAL DE LA JUGADA
void updateFicha(tablero* tab, int id, char ficha) {
  tab->jugada[id].ficha = ficha;
}

//obtener la direccion para una coordenada de jugada en concreto
play_direccions getDireccion (jugadaPosible* play, jugadaPosible plays[]) {
  play_direccions direcciones[3];
  return *direcciones;
}

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
  return 0;
}

//iniciar el array jugadasPosibles o "limpiarlo"
void iniciarPlays (jugadaPosible plays[]){
  for(int i = 0; i < 64; i++){
      plays[i].coord_inicio.x = 0;
      plays[i].coord_inicio.y = 0;
      for (int j = 0; j < 8; j++){
        plays[i].coord_fin[j].x = 0;
        plays[i].coord_fin[j].y = 0;
        strcpy(plays[i].play_direccion[j].direccion, "none");
      }
      plays[i].isPlay = false;
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
  tab->jugada[27].x = 4;
  tab->jugada[27].y = 4;
  tab->jugada[27].ficha = 'O';
  tab->jugada[27].empty = false;

  tab->jugada[28].x = 4;
  tab->jugada[28].y = 5;
  tab->jugada[28].ficha = 'X';
  tab->jugada[28].empty = false;
  
  tab->jugada[35].x = 5;
  tab->jugada[35].y = 4;
  tab->jugada[35].ficha = 'X';
  tab->jugada[35].empty = false;

  tab->jugada[36].x = 5;
  tab->jugada[36].y = 5;
  tab->jugada[36].ficha = 'O';
  tab->jugada[36].empty = false;
}

//mostrar las jugadas que sean validas para la ficha que este actualmente en juego
void showPlays (jugadaPosible plays[]){
  for(int i = 0; i < 64; i++){
    // si tiene 8 jugadas
    if(plays[i].isPlay == 1 && plays[i].coord_fin[0].x != 0 && plays[i].coord_fin[1].x != 0 && plays[i].coord_fin[2].x != 0 && plays[i].coord_fin[3].x != 0 && plays[i].coord_fin[4].x != 0 && plays[i].coord_fin[5].x != 0 
      && plays[i].coord_fin[6].x != 0 && plays[i].coord_fin[7].x != 0){
      printf("\n-jugada valida en--\n [%d - %d]  --\njugada1|%d - %d| direccion: %s\njugada2|%d - %d| direccion: %s\njugada3|%d - %d| direccion: %s\njugada4|%d - %d| direccion: %s\njugada5|%d - %d| direccion: %s\njugada6|%d - %d| direccion: %s\njugada7|%d - %d| direccion: %s\njugada8|%d - %d| direccion: %s\n", 
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
        plays[i].play_direccion[2].direccion,
        plays[i].coord_fin[3].x,
        plays[i].coord_fin[3].y,
        plays[i].play_direccion[3].direccion,
        plays[i].coord_fin[4].x,
        plays[i].coord_fin[4].y,
        plays[i].play_direccion[4].direccion,
        plays[i].coord_fin[5].x,
        plays[i].coord_fin[5].y,
        plays[i].play_direccion[5].direccion,
        plays[i].coord_fin[6].x,
        plays[i].coord_fin[6].y,
        plays[i].play_direccion[6].direccion,
        plays[i].coord_fin[7].x,
        plays[i].coord_fin[7].y,
        plays[i].play_direccion[7].direccion
      );
    // si tiene 7 jugadas
    }else if(plays[i].isPlay == 1 && plays[i].coord_fin[0].x != 0 && plays[i].coord_fin[1].x != 0 && plays[i].coord_fin[2].x != 0 && plays[i].coord_fin[3].x != 0 && plays[i].coord_fin[4].x != 0 && plays[i].coord_fin[5].x != 0
      && plays[i].coord_fin[6].x != 0){
      printf("\n-jugada valida en--\n [%d - %d]  --\njugada1|%d - %d| direccion: %s\njugada2|%d - %d| direccion: %s\njugada3|%d - %d| direccion: %s\njugada4|%d - %d| direccion: %s\njugada5|%d - %d| direccion: %s\njugada6|%d - %d| direccion: %s\njugada7|%d - %d| direccion: %s\n", 
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
        plays[i].play_direccion[2].direccion,
        plays[i].coord_fin[3].x,
        plays[i].coord_fin[3].y,
        plays[i].play_direccion[3].direccion,
        plays[i].coord_fin[4].x,
        plays[i].coord_fin[4].y,
        plays[i].play_direccion[4].direccion,
        plays[i].coord_fin[5].x,
        plays[i].coord_fin[5].y,
        plays[i].play_direccion[5].direccion,
        plays[i].coord_fin[6].x,
        plays[i].coord_fin[6].y,
        plays[i].play_direccion[6].direccion
      );
    // si tiene 6 jugadas
    }else if(plays[i].isPlay == 1 && plays[i].coord_fin[0].x != 0 && plays[i].coord_fin[1].x != 0 && plays[i].coord_fin[2].x != 0 && plays[i].coord_fin[3].x != 0 && plays[i].coord_fin[4].x != 0 && plays[i].coord_fin[5].x != 0){
      printf("\n-jugada valida en--\n [%d - %d]  --\njugada1|%d - %d| direccion: %s\njugada2|%d - %d| direccion: %s\njugada3|%d - %d| direccion: %s\njugada4|%d - %d| direccion: %s\njugada5|%d - %d| direccion: %s\njugada6|%d - %d| direccion: %s\n", 
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
        plays[i].play_direccion[2].direccion,
        plays[i].coord_fin[3].x,
        plays[i].coord_fin[3].y,
        plays[i].play_direccion[3].direccion,
        plays[i].coord_fin[4].x,
        plays[i].coord_fin[4].y,
        plays[i].play_direccion[4].direccion,
        plays[i].coord_fin[5].x,
        plays[i].coord_fin[5].y,
        plays[i].play_direccion[5].direccion
      );
    // si tiene 5 jugadas
    }else if(plays[i].isPlay == 1 && plays[i].coord_fin[0].x != 0 && plays[i].coord_fin[1].x != 0 && plays[i].coord_fin[2].x != 0 && plays[i].coord_fin[3].x != 0 && plays[i].coord_fin[4].x != 0){
      printf("\n-jugada valida en--\n [%d - %d]  --\njugada1|%d - %d| direccion: %s\njugada2|%d - %d| direccion: %s\njugada3|%d - %d| direccion: %s\njugada4|%d - %d| direccion: %s\njugada5|%d - %d| direccion: %s\n", 
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
        plays[i].play_direccion[2].direccion,
        plays[i].coord_fin[3].x,
        plays[i].coord_fin[3].y,
        plays[i].play_direccion[3].direccion,
        plays[i].coord_fin[4].x,
        plays[i].coord_fin[4].y,
        plays[i].play_direccion[4].direccion
      );
    // si tiene 4 jugadas
    }else if(plays[i].isPlay == 1 && plays[i].coord_fin[0].x != 0 && plays[i].coord_fin[1].x != 0 && plays[i].coord_fin[2].x != 0 && plays[i].coord_fin[3].x != 0){
      printf("\n-jugada valida en--\n [%d - %d]  --\njugada1|%d - %d| direccion: %s\njugada2|%d - %d| direccion: %s\njugada3|%d - %d| direccion: %s\njugada4|%d - %d| direccion: %s\n", 
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
        plays[i].play_direccion[2].direccion,
        plays[i].coord_fin[3].x,
        plays[i].coord_fin[3].y,
        plays[i].play_direccion[3].direccion
      );
    // si tiene 3 jugadas
    }else if(plays[i].isPlay == 1 && plays[i].coord_fin[0].x != 0 && plays[i].coord_fin[1].x != 0 && plays[i].coord_fin[2].x != 0){
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

/*obtener todos los origenes de la jugada que se ingreso
  - ya que una una posicion de origen puede desenvocar en mas de una "linea" aqui se buscan esos origenes, que dada una posicion valida
  para hacer una jugada crearian varias lineas de "accion"
*/
void getAllOrigins(jugadaPosible plays[], jugadaPosible* play, jugadaPosible jugadaMultiple[]) {
  int count = 0;
  for (int i = 0; i < 64; i++){
    for (int j = 0; j < 8; j++){
      if(play->coord_fin[0].x == plays[i].coord_fin[j].x && play->coord_fin[0].y == plays[i].coord_fin[j].y){
        jugadaMultiple[count].coord_inicio.x = plays[i].coord_inicio.x;
        jugadaMultiple[count].coord_inicio.y = plays[i].coord_inicio.y;
        jugadaMultiple[count].coord_fin[0].x = plays[i].coord_fin[j].x;
        jugadaMultiple[count].coord_fin[0].y = plays[i].coord_fin[j].y;
        jugadaMultiple[count].isPlay = true;
        strcpy(jugadaMultiple[count].play_direccion[0].direccion, plays[i].play_direccion[j].direccion); 
        count++;
        continue;
      }
    }
  }
}

/*Para realizar el calculo de "diferencia" entre una casilla de "jugada" y una casilla de "origen" se necesita saber la direccion de la jugada
que se ingreso, luego se realiza el calculo en base a las casillas.
basicamente mientras las coordenadas de la casilla de "origen" sean distintas de la casilla de "jugada" se realiza el calculo que corresponda
las coordenadas que queden entre ambas coordenadas se guardan en un arreglo de enteros y luego seran convertidas al tipo de ficha que corresponda*/
void obtenerIdDeCasillasAfectadas(int* count2, int resultado[], tablero* tab, char* direccion, int origen_x,int origen_y,int fin_x,int fin_y){
  *count2 = 0;
  int x, y;

  if (strcmp(direccion, "diag_sup_izq") == 0) {
      x = -1; y = -1;
  } else if (strcmp(direccion, "vertical+") == 0) {
      x = -1; y = 0;
  } else if (strcmp(direccion, "diag_sup_der") == 0) {
      x = -1; y = 1;
  } else if (strcmp(direccion, "horizontal-") == 0) {
      x = 0; y = -1;
  } else if (strcmp(direccion, "horizontal+") == 0) {
      x = 0; y = 1;
  } else if (strcmp(direccion, "diag_inf_izq") == 0) {
      x = 1; y = -1;
  } else if (strcmp(direccion, "vertical-") == 0) {
      x = 1; y = 0;
  } else if (strcmp(direccion, "diag_inf_der") == 0) {
      x = 1; y = 1;
  }

  //mientras la coordenada de origen no sea la coordenada de final hacer el coso coso de las x e y
  while (origen_x != fin_x || origen_y != fin_y){
  //  printf("1 origen.> %d - %d final-> %d - %d\n", origen_x, origen_y, fin_x, fin_y);
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

//INGRESAR UNA JUGADA, Y CAMBIAR LAS FICHAS AFECTADAS EN DICHA JUGADA return 1 si OK | return 0 si MAL
void ingresarJugada(tablero* tab, jugadaPosible* jugada, jugadaPosible plays[], jugador* player) {
  //conseguir la ficha del jugador actual
  char ficha = player->ficha;

  int count = 0;
  jugadaPosible jugadaMultiple[8];

  for (int i = 0; i < 8; i++){//inicializar jugadaMultiple
    jugadaMultiple[i].coord_inicio.x = 0;
    jugadaMultiple[i].coord_inicio.y = 0;
    jugadaMultiple[i].coord_fin[0].x = 0;
    jugadaMultiple[i].coord_fin[0].y = 0;
    jugadaMultiple[i].coord_fin[1].x = 0;
    jugadaMultiple[i].coord_fin[1].y = 0;
    jugadaMultiple[i].coord_fin[2].x = 0;
    jugadaMultiple[i].coord_fin[2].y = 0;
    jugadaMultiple[i].isPlay = false;
    strcpy(jugadaMultiple[i].play_direccion[0].direccion, "none");
    strcpy(jugadaMultiple[i].play_direccion[1].direccion, "none");
    strcpy(jugadaMultiple[i].play_direccion[2].direccion, "none");
  }
  
  int id[8] = {0};
  // SI las coordenadas de final tienen mas de un origen hay que afectar mas de una direccion, sino... 1 sola direccion

  //en jugada multiple quedan guardadas las jugadas que afecten mas de una LINEA al mismo tiempo, lo que llamare "jugada multiple"
  getAllOrigins(plays, jugada, jugadaMultiple); 

  //checkeo cuantas jugadas multiples hay
  for (int i = 0; i < 8; i++){
    if(jugadaMultiple[i].isPlay){
      count++;
    }
  }

  //1 direccion | if count == 0
  int casillasID[8] = { 0 };
  int count2 = 0; //dependiendo de la cantidad de direcciones que hallan

  for (int i = 0; i < count; i++){
    obtenerIdDeCasillasAfectadas(
      &count2,
      casillasID,
      tab, 
      jugadaMultiple[i].play_direccion[0].direccion,
      jugadaMultiple[i].coord_inicio.x,
      jugadaMultiple[i].coord_inicio.y,
      jugadaMultiple[i].coord_fin[0].x,
      jugadaMultiple[i].coord_fin[0].y
    );

    for (int i = 0; i < count2; i++){
      updateFicha(tab, casillasID[i], ficha); //actualizar el tablero
    }
  }
}

//VALIDAR QUE LA JUGADA INGRESADA PERTENEZCA A LAS JUGADAS VALIDAS
//RETORNA la jugada que el usuario ingrese, si es valida
jugadaPosible validarJugada(jugador* player, jugadaPosible jugadasPosibles[]) {
  jugadaPosible play;
  int x, y;
  bool encontrado = false;

  int showJugadasValidas = 0;

  //si las coordenadas que se ingresan estan en el array de jugadasPosibles, que seria el valor de la casilla vacia, todo OK
  //sino jugada invalida y que vuela a intentarlo
  int topeDeIntentos = 5;
  int i;
  while(!encontrado && topeDeIntentos > 0){
    if((strcmp(player->nombre, "cachito") == 0)){
      printf("Hola cachito!! :)\n");
    }
    printf("Turno --> %s \n", player->nombre);
    printf("ingresa una jugada: \n");
    scanf("%d",&x);
    scanf("%d",&y);
    
    if((x > 0 && x < 9) && (y > 0 && y < 9)){
      for (i = 0; i < 64; i++){
        for (int j = 0; j < 8; j++){
          if(jugadasPosibles[i].coord_fin[j].x == x && jugadasPosibles[i].coord_fin[j].y == y && jugadasPosibles[i].isPlay == true) {
            play.coord_inicio.x = jugadasPosibles[i].coord_inicio.x;
            play.coord_inicio.y = jugadasPosibles[i].coord_inicio.y;
            play.coord_fin[0].x = jugadasPosibles[i].coord_fin[j].x;
            play.coord_fin[0].y = jugadasPosibles[i].coord_fin[j].y;
            strcpy(play.play_direccion[j].direccion, jugadasPosibles[i].play_direccion[j].direccion);
            encontrado = true;
          } 
        }
      }

      if(!encontrado){
        printf("Oops, %d - %d es una casilla invalida :(\n\n", x, y);
        showJugadasValidas++;
        if(showJugadasValidas > 2){
          showPlays(jugadasPosibles);
          printf("\n\n");
        }
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

//encargado de insertar las posibles jugadas en el array de jugadas posibles
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
      break;
    }else if(plays[i].coord_inicio.x == x && plays[i].coord_inicio.y == y){ //quiere decir que para ese valor de origen existen mas direcciones de jugadas posibles
      for (int j = 1; j <= 7; j++){
        if(plays[i].coord_fin[j].x == 0 && plays[i].coord_fin[j].y == 0){//dependiendo de cuantas direcciones de jugadas hayan se ingresan
          plays[i].coord_fin[j].x = fin_x;
          plays[i].coord_fin[j].y = fin_y;
          strcpy(plays[i].play_direccion[j].direccion, direccion);
          break;
        }
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
            // printf("fuera de tablero \n");
            break; //fuera de tablero. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == ficha){
            // printf("ficha del jugador actual \n");
            break; //ficha igual al del jugador. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == '_'){
            //guardar la play
            savePlays(plays, l, x, y, tab->jugada[l].x, tab->jugada[l].y, "horizontal-");
            break;
          }else if(tab->jugada[l].ficha == ficha_oponente){
            //Ficha oponente encontrada en %d %d, seguir buscando
            offset++;
            l = -1;
          }
        }
    l++;
    }
  }else if(direccion == 7){
    while(l < 64){
        if(tab->jugada[l].x == x + offset && tab->jugada[l].y == y){
          if(x + offset == 9){
            // printf("fuera de tablero \n");
            break; //fuera de tablero. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == ficha){
            // printf("ficha del jugador actual \n");
            break; //ficha igual al del jugador. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == '_'){
            savePlays(plays, l, x, y, tab->jugada[l].x, tab->jugada[l].y, "vertical-");
            break;
          }else if(tab->jugada[l].ficha == ficha_oponente){
            //Ficha oponente encontrada en %d %d, seguir buscando
            offset++;
            l = -1;
          }
        }
    l++;
    }
  }else if (direccion == 1){
    while(l < 64){
        if(tab->jugada[l].x == x - offset && tab->jugada[l].y == y - offset){
          if(y - offset == 0 || x - offset == 0){
            // printf("fuera de tablero \n");
            break; //fuera de tablero. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == ficha){
            // printf("ficha del jugador actual \n");
            break; //ficha igual al del jugador. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == '_'){
            savePlays(plays, l, x, y, tab->jugada[l].x, tab->jugada[l].y, "diag_sup_izq");
            break;
          }else if(tab->jugada[l].ficha == ficha_oponente){
            //Ficha oponente encontrada en %d %d, seguir buscando
            offset++;
            l = -1;
          }
        }
    l++;
    }
  }else if (direccion == 2){
    while(l < 64){
        if(tab->jugada[l].x == x - offset && tab->jugada[l].y == y){
          if(x - offset == 0){
            // printf("fuera de tablero \n");
            break; //fuera de tablero. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == ficha){
            // printf("ficha del jugador actual \n");
            break; //ficha igual al del jugador. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == '_'){
            savePlays(plays, l, x, y, tab->jugada[l].x, tab->jugada[l].y, "vertical+");
            break;
          }else if(tab->jugada[l].ficha == ficha_oponente){
            //Ficha oponente encontrada en %d %d, seguir buscando
            offset++;
            l = -1;
          }
        }
    l++;
    }
  }else if (direccion == 3){
    while(l < 64){
        if(tab->jugada[l].x == x - offset && tab->jugada[l].y == y + offset){
          if(x - offset == 0 || y + offset == 9){
            // printf("fuera de tablero \n");
            break; //fuera de tablero. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == ficha){
            // printf("ficha del jugador actual \n");
            break; //ficha igual al del jugador. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == '_'){
            savePlays(plays, l, x, y, tab->jugada[l].x, tab->jugada[l].y, "diag_sup_der");
            break;
          }else if(tab->jugada[l].ficha == ficha_oponente){
            //Ficha oponente encontrada en %d %d, seguir buscando
            offset++;
            l = -1;
          }
        }
    l++;
    }
  }else if (direccion == 5){
    while(l < 64){
        if(tab->jugada[l].x == x && tab->jugada[l].y == y + offset){
          if(y + offset == 9){
            // printf("fuera de tablero \n");
            break; //fuera de tablero. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == ficha){
            // printf("ficha del jugador actual \n");
            break; //ficha igual al del jugador. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == '_'){
            savePlays(plays, l, x, y, tab->jugada[l].x, tab->jugada[l].y, "horizontal+");
            break;
          }else if(tab->jugada[l].ficha == ficha_oponente){
            //Ficha oponente encontrada en %d %d, seguir buscando
            offset++;
            l = -1;
          }
        }
    l++;
    }
  }else if (direccion == 6){
    while(l < 64){
        if(tab->jugada[l].x == x + offset && tab->jugada[l].y == y - offset){
          if(x + offset == 9 || y - offset == 0){
            // printf("fuera de tablero \n");
            break; //fuera de tablero. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == ficha){
            // printf("ficha del jugador actual \n");
            break; //ficha igual al del jugador. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == '_'){
            savePlays(plays, l, x, y, tab->jugada[l].x, tab->jugada[l].y, "diag_inf_izq");
            break;
          }else if(tab->jugada[l].ficha == ficha_oponente){
            //Ficha oponente encontrada en %d %d, seguir buscando
            offset++;
            l = -1;
          }
        }
    l++;
    }
  }else if (direccion == 8){
    while(l < 64){
        if(tab->jugada[l].x == x + offset && tab->jugada[l].y == y + offset){
          if(x + offset == 9 || y + offset == 9){
            // printf("fuera de tablero \n");
            break; //fuera de tablero. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == ficha){
            // printf("ficha del jugador actual \n");
            break; //ficha igual al del jugador. no hay jugada PARAR
          }else if(tab->jugada[l].ficha == '_'){
            savePlays(plays, l, x, y, tab->jugada[l].x, tab->jugada[l].y, "diag_inf_der");
            break;
          }else if(tab->jugada[l].ficha == ficha_oponente){
            //Ficha oponente encontrada en %d %d, seguir buscando
            offset++;
            l = -1;
          }
        }
    l++;
    }
  }
}

//ECONTRAR CASILLAS ADYACENTES
//se buscan casilla adyacentes para una ficha en concreto
void findPlay(jugador* player, tablero* tab, int x, int y, jugadaPosible plays[]){
  coordenada result;
  char ficha_oponente;
  int i = 0;

  int founded = 0;
  
  while(i < 64){
    if (tab->jugada[i].x == x && tab->jugada[i].y == y){
      result.x = tab->jugada[i].x;
      result.y = tab->jugada[i].y;
      break;
    }
    i++;
  }

  if(player->ficha == 'X'){
    ficha_oponente = 'O';
  }else if(player->ficha == 'O'){
    ficha_oponente = 'X';
  }

  int j = 0;
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

  /* referencia
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

void asignarFicha(jugador* player){
  int r = rand() % 21;
  char resultFicha = (r > 10) ? 'X' : 'O';

  if(resultFicha == 'X'){
    player->ficha = 'X';
  }else{
    player->ficha = 'O';
  }
}

//CREAR JUGADORES
void crearJugador(jugador player[]) {
    printf("Ingrese los datos de los jugadores\n");
    printf("Jugador 1\n");
    printf("Nombre: ");
    scanf("%s", player[0].nombre);
    asignarFicha(&player[0]);
    player[0].turno = 0;
    player[0].turnoActual = false;
    printf("Se te asigno la ficha: %c\n", player[0].ficha);
    printf("\n");

    if(player[0].ficha == 'X'){
      player[1].ficha = 'O';
    }else if(player[0].ficha == 'O'){
      player[1].ficha = 'X';
    }
    
    printf("Jugador 2\n");
    printf("Nombre: ");
    scanf("%s", player[1].nombre);
    player[1].turno = 0;
    player[1].turnoActual = false;
    printf("%c\n", player[1].ficha);
    printf("\n");
}

jugador actualizarTurno(jugador player[]){
  if(player[0].turnoActual == false && player[1].turnoActual == false){//primer movimiento
    if(player[0].ficha == 'X'){
      player[0].turno++;
      player[0].turnoActual = true;
      return player[0];
    }else if(player[1].ficha == 'X'){
      player[1].turno++;
      player[1].turnoActual = true;
      return player[1];
    }
  }else{//siguientes movimientos
    if(player[0].turnoActual == true){
      player[1].turno++; //el player 0 fue el ultimo
      player[1].turnoActual = true;
      player[0].turnoActual = false;
      return player[1];
    }else if(player[1].turnoActual == true){
      player[0].turno++; //el player 1 fue el ultimo
      player[0].turnoActual = true;
      player[1].turnoActual = false;
      return player[0];
    }
  }

  jugador jugadorVacio;
  strcpy(jugadorVacio.nombre, "none");
  jugadorVacio.ficha = 'W';
  return jugadorVacio;
}

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
void showInfo(tablero* tab, jugador player[]){
  printf("%s -> Ficha: %c Cantidad: %d | Turno actual: %d\n", 
    player[0].nombre,
    player[0].ficha,
    contarFichas(tab, player[0].ficha),
    player[0].turno
  );

  printf("%s -> Ficha: %c Cantidad: %d | Turno actual: %d\n", 
    player[1].nombre, 
    player[1].ficha, 
    contarFichas(tab, player[1].ficha),
    player[1].turno
  );

  printf("\n\n");
}

// MAIN 
int main() {
//------------------------------------------------------------------------------------------------------------------------- INICIO DEL JUEGO
  jugador jugadores[2];
  tablero tab;
  jugadaPosible play[64];
  coordenada test;
  jugador player;
  jugadaPosible jugada;
  int hayJugadaPosible;
  int noHayJugada = 0;
  int turnosRestantes = 60;

  srand(time(NULL));

  printf("\n");
  printf("Bienvenido..\n");
  printf("\nPara ingresar una jugada primero se ingresa el numero de fila (se presiona enter) y luego el de columna (y se presiona enter nuevamente)...\n");
  printf("\nSi se ingresa una jugada invalida 3 veces el programa mostrara un mensaje con las jugadas validas para ese jugador...\n\n");

  crearJugador(jugadores);

  iniciarTablero(&tab); //INICIA EL TABLERO

//------------------------------------------------------------------------------------------------------------------------- EN JUEGO (LOOP)
  for (int i = 0; i < 60; i++)
  {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Turnos restantes -->> %d\n", turnosRestantes);
    //contar fichas

    iniciarPlays(play); //INICIA LAS JUGADAS VALIDAS EN "0"
    
    player = actualizarTurno(jugadores); //DA EL TURNO
    
    //HACE UN BARRIDO DE TODAS LAS FICHAS DEL JUGADOR ACTUAL Y BUSCA SUS JUGADAS VALIDAS
    posicionFichas(&player, &tab, play);

    hayJugadaPosible = chckearSiHayJugadas(play);
    //----------------------------------------------------------------------------------------------- NO HAY JUGADA POSIBLE!
    if(hayJugadaPosible == 0 && noHayJugada < 2){
      noHayJugada++;
      continue;
    }else if(hayJugadaPosible == 0 && noHayJugada >= 2){
      printf("Se termino el juego... \n");
      showInfo(&tab, jugadores); //con la info de los jugadores
      renderTablero(&tab);
      //contar fichas
      int negras = contarFichas(&tab, 'X');
      int blancas = contarFichas(&tab, 'O');

      mensajeFinal(negras, blancas);
      break;
    }
    //----------------------------------------------------------------------------------------------- SI NO HAY JUGADA POSIBLE X2 termina ACA

    //MUESTRA LAS JUGADAS VALIDAS
    // showPlays(play); 

    //MUESTRA EL ESTADO ACTUAL DEL TABLERO
    showInfo(&tab, jugadores); //con la info de los jugadores
    renderTablero(&tab);
    printf("\n\n");

    //PIDE UNA COORDENADA DE JUGADA VALIDA Y LA GUARDA EN "JUGADA"
    jugada = validarJugada(&player, play);

    //SE INGRESA LA JUGADA Y SE ACTUALIZAN LAS FICHAS DEL TABLERO
    ingresarJugada(&tab, &jugada, play, &player);

    if(i == 60){
      printf("Se terminaron los turnos.... saliendo...\n");
      showInfo(&tab, jugadores); //con la info de los jugadores
      renderTablero(&tab);
      
      int negras = contarFichas(&tab, 'X');
      int blancas = contarFichas(&tab, 'O');

      mensajeFinal(negras, blancas);
      break;
    }

    turnosRestantes--;
  }
//------------------------------------------------------------------------------------------------------------------------- FIN EN JUEGO (LOOP)
  printf("fin de ejecucion");
} 