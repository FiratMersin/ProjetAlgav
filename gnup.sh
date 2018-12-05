plot "ConIterFB.time" with lines
set term postscript landscape
set output "Graphe_temps_execution_FB.ps"
set size 2, 1
set title 'ConsIter FB'
set xlabel 'nombre de clefs'
set ylabel 'temps d execution (secondes)'
replot 
