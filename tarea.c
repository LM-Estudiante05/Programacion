#include <stdio.h>

int main(){
    int stock ,opcion,salir;
    float precioU, ganancias = 0;
    char nombre, ID;

    do
    {
        int cantidad = 0, segundos=0;
        salir = 0;
        printf("1. Registrar producto \n 2.- Vender \n 3.- Reabastecer \n 4.- Revisar Stock \n 5.Ganancias \n ->");
        do
        {
            scanf("%d", &opcion);
            switch (opcion)
            {
            case 1:
                printf("ID Producto ->");
                scanf ("%s", &ID);
                printf ("ingresar nombre del producto->");
                scanf ("%s", &nombre);
                printf ("cantidad en stock ->");
                scanf ("%d",&stock);
                printf ("Precio Unitario ->");
                scanf ("%f", &precioU);
                printf ("*Producto agregado*");
                break;
            case 2:
                printf ("Cantidad de producto que desea vender ->");
                scanf("%d", &cantidad);
                if (cantidad > stock){
                    printf ("Stock insuficiente, restablecer stock");
                } else {
                    stock = stock - cantidad;
                    ganancias = ganancias + (cantidad * precioU);
                    printf("Venta completada, gracias por su compra.");
                
                }
                break;

            case 3:
            printf ("\nla cantidad de stock es %d", stock);
            printf ("\nCantidad de stock que desea agregar ->");
            scanf ("%d", &segundos);
            stock = stock + segundos;
            break;
        case 4:
            printf("El stock actual es %d", stock);
            break;
        case 5:
            printf("\n Ganancias obtenidas %.2f", ganancias);
            break;
        default:
        printf("ERROR ELECCION NO VALIDA \n");
            break;
        }
    } while (opcion < 1 || opcion >= 6);
    printf("\nDesea continuar, ingrese 1 ->");
    scanf("%d", &salir);
    } while (salir == 1);
    
}