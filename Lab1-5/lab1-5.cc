/*
 * lab1-5.cc
 */
// Inkluderingar efter behov

// Deklarera en funktion build_lists(instrˆm, list_1, list_2) som l‰ser namn 
// frÂn instrˆmmen och anv‰nder insert() fˆr att s‰tta in i list_1 och append()
// fˆr att s‰tta in i list_2. build_lists() ska definieras efter main().

// Komplettera och modifiera:

int main()
{
   // Kontrollera att ett argument (filnamn) angivits pÂ kommandoraden.
   // Om inte skriv ut ett felmeddelande och avsluta programmet.

   // ÷ppna en infilstrˆm fˆr den fil vars namn givits pÂ kommandoraden. 
   // Kontrollera att ˆppningen lyckas, om inte ska ett felmeddelande 
   // skrivas ut och programmet avslutas.

   // Deklarera tvÂ tomma listor, list_1 och list_2

   // Kontrollera med empty() att listorna ‰r tomma och skriv ut det.

   // Anropa build_lists() fˆr att l‰sa namn frÂn indata och s‰tta in i namnen
   // i list_1 och list_2, enligt vad som sagts om build_lists() ovan.
   
   cout << "Lista 1 efter inl‰sning av namn:\n";
   // Skriv ut list_1 med print()
   cout << "Lista 2 efter inl‰sning av namn:\n";
   // Skriv ut list_2 med print()

   cout << "Lista 1 utskriven i omv‰nd ordning:\n";
   // Skriv ut list_1 med print_reversed()

   cout << "Lista 1 v‰nds.\n";
   // V‰nd innehÂllet i list_1 med reverse();
   cout << "Lista 1 efter v‰ndning:\n";
   // Skriv ut list_1 med print()

   cout << "Lista 2 raderas.\n";
   // Radera list_2 med clear()
   if (empty(list_2))
      cout << "Lista 2 ‰r tom.\n";
   else
      cout << "Lista 2 ‰r inte tom.\n";

   cout << "Lista 2 tilldelas en kopia av lista 1.\n";
   // Anv‰nd copy() fˆr att kopiera list_1
   cout << "Lista 2 innehÂller:\n";
   // Skriv ut list_2 med print()

   cout << "Lista 2 raderas.\n";
   // Radera list_2 med clear()
   cout << "Lista 1 och 2 byter innehÂller.\n";
   // Anv‰nd swap()
   if (empty(list_1))
      cout << "Lista 1 ‰r tom.\n";
   else
      cout << "Lista 1 ‰r inte tom.\n";
   cout << "Lista 2 innehÂller:\n";
   // Skriv ut list_2 med print()

   cout << "Lista 2 raderas.\n";
   // Radera list_2 med clear()

   // Kontrollera med empty() att listorna ‰r tomma och skriv ut det.

   cout << "Programmet avslutas.\n";

   return 0;
}
