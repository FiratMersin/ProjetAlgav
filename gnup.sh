plot "SupprMinTasTab.time" with lines
set term postscript landscape
set output "Graphe_temps_execution_SupprMin_TasTab.ps"
set size 2, 1
set title 'SupprMin TasTab'
set xlabel 'nombre de clefs'
set ylabel 'temps d execution (secondes)'
replot 
