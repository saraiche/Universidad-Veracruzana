public class Main
{
	public static void main(String[] args)
	{
		ExperienciaEducativa arr[] = new ExperienciaEducativa [10];
		arr[0] = new ExperienciaEducativa("probando", 10);

		System.out.println(arr[0].getClave() + " " + arr[0].getTotalDeCreditos());
		Curso cursito = new Curso("codigosinsentido", 10, 2);
		Profesor prof = new Profesor("75", "jose martinez", "de planta");
		Academia aca = new Academia("Academia de testeo");
		prof.addCurso(cursito);
		prof.addAcademia(aca);
		cursito.addDocente(prof);
		arr[0].addCurso(cursito);
		System.out.println("La Experiencia: "+ arr[0].getClave() + "Es dirigida por el profesor \n Nombre del profesor: " +arr[0].getCurso().getDocente().getNombre());
		System.out.println("el cual pertenece a la academia: " +arr[0].getCurso().getDocente().getAcademia().getNombre());
		System.out.println("Y tiene " + arr[0].getCurso().getDocente().getNumCurso() + " Cursos" ) ;
		System.out.println("Las cuales se llaman\n");
		prof = arr[0].getCurso().getDocente();
		for(int c = 0 ; c<prof.getNumCurso(); c++)
			System.out.print(prof.getCurso(c).getNrc() + " ");

	}
}