plot "uniontasTab.time" with lines
set term postscript landscape
set output "Graphe_temps_execution_Union_TasTab.ps"
set size 2, 1
set title 'Union Tas Tab'
set xlabel 'nombre de clefs (après union)'
set ylabel 'temps d execution (secondes)'
replot 
