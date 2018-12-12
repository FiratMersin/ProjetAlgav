plot "ConsIterTasTab.time" with lines
set term postscript landscape
set output "Graphe_temps_execution_ConsIter_TasTab.ps"
set size 2, 1
set title 'ConsIter Tas Tab'
set xlabel 'nombre de clefs'
set ylabel 'temps d execution (secondes)'
replot 
