public class Academia{
	private String nombre;
	private Profesor coordinador;
	private ExperienciaE [] ee = new ExperienciaEducativa[3];
	private numExperiencia = 0;
	
	public Academia(){
	}

	public Academia(String nomb){
		this.nombre = nomb;
	}

	public Academia(String nombre, Profesor coor){
		this.nombre = nomb;
		this.coordinador = coor;
	}

	public void setNombre(String nomb){
		this.nombre = nomb;
	}


	public String getNombre(){
		return nombre;
	}

	public void setCoordinador(Profesor coor){
		this.coordinador = coor;
	}


	public String getCoordinador(){
		return coordinador;
	}

	public void addExperiencia(ExperienciaE ee){
		if (numExperiencia<4){
			this.ee[numExperiencia] = ee;
			numExperiencia++
		} else
			System.out.println("No hay capacidad para más experiencias educativas");
	}

	public ExperienciaE getEE(int i){
		return ee[i];
	}

}