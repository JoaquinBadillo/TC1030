#include <iostream>

#include "shipment.hpp"
#include "package.hpp"
#include "envelope.hpp"

int main(void)
{
    Package p1("Adolfo", "Labna 29", "Cancún", "Quintana Roo", "77500", "Javier", "Francisco I. Madero 43", "Poza Rica", "Veracruz", "92517", false, 1, 1, 1, 20, 15);
    Package p2("Claudia", "Blvd Carranza y Aldama", "Ensenada", "Baja California", "22840", "Laura", "Juárez Sur 433", "Texcoco", "Estado de México", "56190", false, 3, 5, 6, 10, 15);
    Package p3("María", "Moliere 450", "CDMX", "CDMX", "11520", "Juan", "Av Ricardo B. Anaya 1131", "San Luis Potosí", "San Luis Potosí", "78070",  false, 4, 6, 2, 16, 17);
    Package p4("Nombre X", "Lugar X", "Ciudad X", "Estado X", "00000", "Nombre Y", "Dirección Y", "Ciudad Y", "Estado Y", "11111", false, 10, 13, 14, 34, 15);
    Envelope p5("Ernesto", "Av. Coyoacán 100", "CDMX", "CDMX", "17981", "Jimena", "Paseo de los Abedules 62550", "Cuernavaca", "Morelos", "62140", false, 5, 15);
    Envelope p6("Estefanía", "Calzada de las Bombas 774", "CDMX", "CDMX", "04930", "Víctor", "Benito Juárez 203", "Papantla", "veracruz", "93400", false, 27, 35);
    Envelope p7("Gerardo", "Calle 14 81", "Mérida", "Yucatán", "97139", "Raúl", "Rio Tampaon 117", "San Luis Potosí", "San Luis Potosí", "78160", false, 10, 8);
    Envelope p8("Nombre A", "Dirección A", "Ciudad A", "Estado A", "22222", "Nombre B", "Dirección B", "Ciudad B", "Estado B", "33333", false, 31, 26);

    Shipment* shipments[8] = {&p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8};
    double totalCost = 0;
    for (int i=0; i<8; i++)
    {
        std::cout << "Shipment from: \n";
        std::cout << shipments[i] -> getSenderLocation() << "\n";
        std::cout << shipments[i] -> getSenderCity() << ", " << shipments[i] -> getSenderState() << "\n";
        std::cout << shipments[i] -> getSenderZipCode() << "\n\n";

        std::cout << "For: \n";
        std::cout << shipments[i] -> getAddresseeLocation() << "\n";
        std::cout << shipments[i] -> getAddresseeCity() << ", " << shipments[i] -> getAddresseeState() << "\n";
        std::cout << shipments[i] -> getAddresseeZipCode() << "\n\n";

        double cost = shipments[i] -> computePrice();

        std::cout << "Price: $" << cost << "\n";

        totalCost += cost;

        std::cout << "-----------------------\n";
    }

    std::cout << "Total Shipment cost: $" << totalCost << "\n";
    return 0;
}