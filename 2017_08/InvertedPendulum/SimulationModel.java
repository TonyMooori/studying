public interface SimulationModel {
    public abstract Mat dxdt(Mat x,float t,Mat params);
}