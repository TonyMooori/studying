// 状態変数を微分したものを返す関数のインターフェイス
public interface SimulationModel {
    public abstract Mat dxdt(Mat x,float t,Mat params);
}