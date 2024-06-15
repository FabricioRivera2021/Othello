#include<stdio.h>
#include<stdbool.h>

//parte de render tablero
// if(i == player[0].coord[coordIndexP1].x && j == player[0].coord[coordIndexP1].y){
//   printf(" %c ", player[0].ficha);
//   coordIndexP1++;//si se encontro una ficha se aumenta el indice del array de coordenadas, para buscar mas
// }else if(i == player[0].coord[turno].x && j == player[0].coord[turno].y){
//   printf(" %c ", player[0].ficha);
// }else if(i == player[1].coord[coordIndexP2].x && j == player[1].coord[coordIndexP2].y){
//   printf(" %c ", player[1].ficha);
//   coordIndexP2++;//si se encontro una ficha se aumenta el indice del array de coordenadas, para buscar mas


//movimientosPosibles (fichas, nro_movimiento)
//-validar jugadas
//-validar ganador si no hay jugadas

typedef struct {
  int x;
  int y;
  char ficha;
} coordenada;

typedef struct {
  coordenada coord_inicio;
  coordenada coord_fin;
  char direccion[10];
} jugadaPosible;

typedef struct {
  coordenada jugada[64];
  int nro_turno;
} tablero;

typedef struct {
  int id;
  char nombre[60]; 
  char ficha; //ficha que este usando el jugador
  int turno; //contador de turnos
  bool ultimoTurno; //para saber quien tuvo el ultimo turno
} jugador;

//MOVIMIENTOS POSIBLES
void movimientosPosible(jugador player[], tablero* tab, jugadaPosible jugadaPosibles[]) {
  jugadaPosible jugadasPosibles[60];
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      /* buscar ficha igual a la del jugador actual
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
    }
  }

  //guardarlo en el array de jugadas posibles
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
void ingresarJugada(jugador player[], tablero* tab, int id, int coord_x, int coord_y) {
  //aumenta el contador de turno 
  player[id].turno+=1;
  int turn = player[id].turno;
  char ficha = player[id].ficha;
  int x = coord_x;
  int y = coord_y;

  tab->jugada[tab->nro_turno].x = x;
  tab->jugada[tab->nro_turno].y = y;
  tab->jugada[tab->nro_turno].ficha = ficha;
  tab->nro_turno++;
}

//actualmente asignar ficha ingresa una "X" si el indice del jugador es 0
// y una "O" si el indice es 1. hay que hacerlo ALEATORIO
char asignarFicha(int option){
  char ficha;
  for (int i = 1; i <= 2; i++){
    if(option == 0){
      ficha = '!';
    }else if(option == 1){
      ficha = '!';
    }
  }
  return ficha;
}

//INICIAR TABLERO
void iniciarTablero(tablero* tab){
  tab->nro_turno = 0;
  tab->jugada[tab->nro_turno].x = 4;
  tab->jugada[tab->nro_turno].y = 5;
  tab->jugada[tab->nro_turno].ficha = 'X';
  tab->nro_turno++; //1
  tab->jugada[tab->nro_turno].x = 5;
  tab->jugada[tab->nro_turno].y = 4;
  tab->jugada[tab->nro_turno].ficha = 'X';
  tab->nro_turno++; //2
  tab->jugada[tab->nro_turno].x = 4;
  tab->jugada[tab->nro_turno].y = 4;
  tab->jugada[tab->nro_turno].ficha = 'O';
  tab->nro_turno++; //3
  tab->jugada[tab->nro_turno].x = 5;
  tab->jugada[tab->nro_turno].y = 5;
  tab->jugada[tab->nro_turno].ficha = 'O';
  tab->nro_turno++;

}

//CREAR JUGADORES
void crearJugador(jugador player[], int tope) {
  for(int i = 0; i < tope; i++){
    printf("Ingrese los datos de los jugadores\n");
    printf("Jugador %d\n", i + 1);
    printf("Nombre: ");
    scanf("%s", player[i].nombre);
    player[i].ficha = asignarFicha(i);
    player[i].turno = 1;
    player[i].id = i;
    printf("\n");
  }
}

//codigo en el HP NO TE OLVIDES!!!------------------------------------------------------------------------------
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
        ficha = false;
        for (int k = 0; k < 64; k++){
          if (i == tab->jugada[k].x && j == tab->jugada[k].y){
            printf(" %c ", tab->jugada[k].ficha);
            ficha = true;
            break;//si hay ficha break
          }
        }

        //si no hay ficha, hay espacio vacio.... y si
        if(ficha == false){
          printf(" _ ");
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

// MAIN ************************************************************************************************
int main() {
  jugador jugadores[2];
  tablero tab;

  crearJugador(jugadores, 2);

  iniciarTablero(&tab);

  showInfo(jugadores);

  renderTablero(&tab);

  int primerTurno = darTurno(jugadores);

  ingresarJugada(jugadores, &tab, 0, 4, 3);

  renderTablero(&tab);

  showInfo(jugadores);

  ingresarJugada(jugadores, &tab, 1, 5, 6);

  renderTablero(&tab);

  showInfo(jugadores);
  
  ingresarJugada(jugadores, &tab, 0, 3, 4);

  renderTablero(&tab);

  showInfo(jugadores);

  ingresarJugada(jugadores, &tab, 1, 6, 5);

  renderTablero(&tab);

  showInfo(jugadores);
} 