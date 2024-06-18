#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
  int x;
  int y;
  char ficha;
  bool empty;
} coordenada;

typedef struct {
  coordenada coord_inicio;
  coordenada coord_fin;
  char direccion[10];
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

<<<<<<< HEAD
//FIND conrdenada after first coordenada
// direccion: 1DIAG-SUP-IZQ 2ARRIBA 3DIAG-SUP-DER 4H-IZQ 5H-DER 6DIAG-INF-IZQ 7-ABAJO 8V-INF-DER
int find(tablero* tab, int x, int y, int offset, int direccion, char ficha){
  int l = 0;
  if(direccion == 4){
    while(l < 64){
        if(tab->jugada[l].x == x && tab->jugada[l].y == y - offset){
          if(y - offset <= 0){
            printf("fuera de tablero");
            return 0;
          }else if(tab->jugada[l].ficha == ficha){
            printf("ficha del jugador actual");
            return 0;
          }else if(tab->jugada[l].ficha == '_'){
            printf("Espacio vacio en:%d %d | %c\n",
              tab->jugada[l].x,
              tab->jugada[l].y,
              tab->jugada[l].ficha
            );
            return 1;
          }
        }
    l++;
  }
  }else if(direccion == 7){
    while(l < 64){
      if(tab->jugada[l].x == x + offset && tab->jugada[l].y == y){
          printf("--------  %d %d | %c\n",
            tab->jugada[l].x,
            tab->jugada[l].y,
            tab->jugada[l].ficha
          );  
      }
    l++;
  }
  }else if (direccion == 1){
    while(l < 64){
      if(tab->jugada[l].x == x - offset && tab->jugada[l].y == y - offset){
          printf("--------  %d %d | %c\n",
            tab->jugada[l].x,
            tab->jugada[l].y,
            tab->jugada[l].ficha
          );  
      }
      l++;
    }
  }else if (direccion == 2){
    while(l < 64){
      if(tab->jugada[l].x == x - offset && tab->jugada[l].y == y ){
          printf("--------  %d %d | %c\n",
            tab->jugada[l].x,
            tab->jugada[l].y,
            tab->jugada[l].ficha
          );  
      }
      l++;
    }
  }else if (direccion == 3){
    while(l < 64){
      if(tab->jugada[l].x == x - offset && tab->jugada[l].y == y + offset ){
          printf("--------  %d %d | %c\n",
            tab->jugada[l].x,
            tab->jugada[l].y,
            tab->jugada[l].ficha
          );  
      }
      l++;
    }
  }else if (direccion == 5){
    while(l < 64){
      if(tab->jugada[l].x == x && tab->jugada[l].y == y + offset ){
          printf("--------  %d %d | %c\n",
            tab->jugada[l].x,
            tab->jugada[l].y,
            tab->jugada[l].ficha
          );  
      }
      l++;
    }
  }else if (direccion == 6){
    while(l < 64){
      if(tab->jugada[l].x == x + offset && tab->jugada[l].y == y - offset ){
          printf("--------  %d %d | %c\n",
            tab->jugada[l].x,
            tab->jugada[l].y,
            tab->jugada[l].ficha
          );  
      }
      l++;
    }
  }else if (direccion == 8){
    while(l < 64){
      if(tab->jugada[l].x == x + offset && tab->jugada[l].y == y + offset ){
          printf("--------  %d %d | %c\n",
            tab->jugada[l].x,
            tab->jugada[l].y,
            tab->jugada[l].ficha
          );  
      }
      l++;
    }
  }
  
}

//ECONTRAR COORDENADA
coordenada findCoordenada(jugador player[], tablero* tab, int x, int y){
=======
//ECONTRAR COORDENADA
coordenada findCoordenada(tablero* tab, int x, int y){
>>>>>>> bee2e9889197543172821e74af27c2dbec368e7d
  coordenada result;
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

  while(j < 64){
<<<<<<< HEAD
    //diagonal
=======
>>>>>>> bee2e9889197543172821e74af27c2dbec368e7d
    if (tab->jugada[j].x == result.x - 1 && tab->jugada[j].y == result.y - 1 && tab->jugada[j].ficha == 'O'){
      printf("%d %d | %c\n",
        tab->jugada[j].x,
        tab->jugada[j].y,
        tab->jugada[j].ficha
      );
    }
<<<<<<< HEAD
    //arriba
=======
>>>>>>> bee2e9889197543172821e74af27c2dbec368e7d
    if (tab->jugada[j].x == result.x - 1 && tab->jugada[j].y == result.y && tab->jugada[j].ficha == 'O'){
      printf("%d %d | %c\n",
        tab->jugada[j].x,
        tab->jugada[j].y,
        tab->jugada[j].ficha
      );
    }
<<<<<<< HEAD
    //diagonal
=======
>>>>>>> bee2e9889197543172821e74af27c2dbec368e7d
    if (tab->jugada[j].x == result.x - 1 && tab->jugada[j].y == result.y + 1 && tab->jugada[j].ficha == 'O'){
      printf("%d %d | %c\n",
        tab->jugada[j].x,
        tab->jugada[j].y,
        tab->jugada[j].ficha
      );
    }
<<<<<<< HEAD
    //derecha
=======
>>>>>>> bee2e9889197543172821e74af27c2dbec368e7d
    if (tab->jugada[j].x == result.x && tab->jugada[j].y == result.y + 1 && tab->jugada[j].ficha == 'O'){
      printf("%d %d | %c\n",
        tab->jugada[j].x,
        tab->jugada[j].y,
        tab->jugada[j].ficha
      );
    }
<<<<<<< HEAD
    //izquierda
=======
>>>>>>> bee2e9889197543172821e74af27c2dbec368e7d
    if (tab->jugada[j].x == result.x && tab->jugada[j].y == result.y - 1 && tab->jugada[j].ficha == 'O'){
      printf("%d %d | %c\n",
        tab->jugada[j].x,
        tab->jugada[j].y,
        tab->jugada[j].ficha
      );
<<<<<<< HEAD
      
      // int find(tablero* tab, int x, int y, int offset, int direccion, char ficha)
      // int offset = 1;
      // while(find(tab, result.x, result.y, offset, 4, player[0].ficha) == 0){
      //   offset++;
      // }

      find(tab, result.x, result.y, 1, 4, player[0].ficha);
    }
    //diagonal
=======
    }
>>>>>>> bee2e9889197543172821e74af27c2dbec368e7d
    if (tab->jugada[j].x == result.x + 1 && tab->jugada[j].y == result.y - 1 && tab->jugada[j].ficha == 'O'){
      printf("%d %d | %c\n",
        tab->jugada[j].x,
        tab->jugada[j].y,
        tab->jugada[j].ficha
      );
<<<<<<< HEAD

      // void find(tablero* tab, int x, int y, int offset)
      find(tab, result.x, result.y, 2, 6, player[0].ficha);
      find(tab, result.x, result.y, 3, 6, player[0].ficha);
    }
    //abajo
=======
    }
>>>>>>> bee2e9889197543172821e74af27c2dbec368e7d
    if (tab->jugada[j].x == result.x + 1 && tab->jugada[j].y == result.y && tab->jugada[j].ficha == 'O'){
      printf("%d %d | %c\n",
        tab->jugada[j].x,
        tab->jugada[j].y,
        tab->jugada[j].ficha
      );
<<<<<<< HEAD
            
      // void find(tablero* tab, int x, int y, int offset, direccion)
      find(tab, result.x, result.y, 2, 7, player[0].ficha);
      find(tab, result.x, result.y, 3, 7, player[0].ficha);
      find(tab, result.x, result.y, 4, 7, player[0].ficha);
    }
    //diagonal
=======
    }
>>>>>>> bee2e9889197543172821e74af27c2dbec368e7d
    if (tab->jugada[j].x == result.x + 1 && tab->jugada[j].y == result.y + 1 && tab->jugada[j].ficha == 'O'){
      printf("%d %d | %c\n",
        tab->jugada[j].x,
        tab->jugada[j].y,
        tab->jugada[j].ficha
      );
    }
    j++;
  }

  /*
<<<<<<< HEAD
  // direccion: 
    1DIAG-SUP-IZQ 2ARRIBA 3DIAG-SUP-DER 4H-IZQ 5H-DER 6DIAG-INF-IZQ 7-ABAJO 8V-INF-DER
    [-1 -1 ]      [-1 0]  [-1 +1]       [0 -1] [0 +1] [+1 -1]       [+1 0]  [+1 +1]
=======
    -1 -1
    -1 0
    -1 +1

    0 -1
    0 +1

    +1 -1
    +1 0
    +1 +1
>>>>>>> bee2e9889197543172821e74af27c2dbec368e7d
  */
  return result;
}

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
  coordenada jugada_posible[60];
  char ficha_a_buscar = player[1].ficha;
  char ficha_oponente = player[0].ficha;
  bool ficha;
  
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      /* buscar ficha igual a la del jugador actual */
      for (int k = 0; k < 64; k++){
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
}

void validarJugada(jugador player[], jugadaPosible jugadasPosibles[]) {
  printf("Ingresa una jugada valida cachito, y mas te vale que sea valida :)");
  // scanf("%d%d",

  // );
  //si las coordenadas que se ingresan estan en el array de jugadasPosibles, que seria el valor de la casilla vacia, todo OK
  //sino jugada invalida y que vuela a intentarlo

  //si jugada OK, hay que pasarla a la funcion de ingresar jugada, con los valores que correspondan
}

/**FUNCION IMPORTANTE
 * Deberia tomar como valores una coordenada de inicio, una coordenada de fin y una direccion
 * y modificar todas las fichas que se vean afectadas en la jugada
 */
void ingresarJugada(jugador player[], int id, tablero* tab, jugadaPosible* play) {
  //aumenta el contador de turno 
  player[id].turno+=1;
  int turn = player[id].turno;
  char ficha = player[id].ficha;
  int x_inicio = play->coord_inicio.x;
  int y_inicio = play->coord_inicio.y;
  int x_fin = play->coord_fin.x;
  int y_fin = play->coord_fin.y;

  //revisar-------------------------------------------------------°!!!!!!!!
  // tab->jugada[tab->casila_id].x = x_inicio;
  // tab->jugada[tab->casila_id].y = y_inicio;
  // tab->jugada[tab->casila_id].ficha = ficha;
  // tab->casila_id++;
}

void asignarFicha(jugador player[]){//revisar que sea aleatorio realmente
  double valor = (double)rand() / (double)RAND_MAX;
  char resultFicha = (valor >= 0.5) ? 'X' : 'O';

  printf("%f", valor);

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
  tab->coordenada_id = 0;
  tab->jugada[27].x = 5;
  tab->jugada[27].y = 4;
  tab->jugada[27].ficha = 'X';
  tab->jugada[27].empty = false;

  tab->jugada[28].x = 4;
  tab->jugada[28].y = 5;
  tab->jugada[28].ficha = 'X';
  tab->jugada[28].empty = false;

  tab->jugada[35].x = 4;
  tab->jugada[35].y = 4;
  tab->jugada[35].ficha = 'O';
  tab->jugada[35].empty = false;

  tab->jugada[36].x = 5;
  tab->jugada[36].y = 5;
  tab->jugada[36].ficha = 'O';
  tab->jugada[36].empty = false;

  tab->coordenada_id = 4;
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

int darTurno(jugador player[]){
  int id;
  if(player[0].turno == 1 && player[1].turno == 1){//primer movimiento
    if(player[0].ficha == 'X'){
      id = 0;
    }else{
      id = 1;
    }
  }
  
  // sino checkear jugadores.ultimoTurno
  //   si ultimoTurno true
  //     dar turno al otro jugador
  //   -
  // -
  return id;
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
  jugadaPosible play;
  coordenada test;

  srand(time(NULL));

  crearJugador(jugadores, 2);

  iniciarTablero(&tab);

  int primerTurno = darTurno(jugadores);

<<<<<<< HEAD
  test = findCoordenada(jugadores ,&tab, 4, 5);
=======
  test = findCoordenada(&tab, 4, 5);
>>>>>>> bee2e9889197543172821e74af27c2dbec368e7d
  printf("\n-------\n%d %d | %c\n------\n\n",
    test.x,
    test.y,
    test.ficha
  );

  // movimientosPosible(jugadores, &tab);

  // ingresarJugada(jugadores, 0, &tab, &play); //OJO ACA

  renderTablero(&tab);

  showInfo(jugadores);
} 