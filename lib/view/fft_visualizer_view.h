#ifndef FFT_VISUALIZER_FFT_VISUALIZER_VIEW_H
#define FFT_VISUALIZER_FFT_VISUALIZER_VIEW_H

#include <fft_visualizer_model.h>

#include "graphs_view.h"
#include "open_cl_info_view.h"
#include "view.h"
#include "worker_picker_view.h"
#include "worker_view.h"

namespace fft_visualizer::view {

class FftVisualizerView final : public View {
  public:
    using Model = model::FftVisualizerModel;

    explicit FftVisualizerView(Model& model);
    void Render() override;

  private:
    bool BeginDockingWindow();
    void EndDockingWindow();
    void InitDockingLayout();
    void RenderMenuBar();
    void RenderErrorPopup();

    Model& model_;
    WorkerView worker_view_;
    OpenClInfoView opencl_info_view_;
    WorkerPickerView worker_picker_view_;
    GraphsView graphs_view_;
    bool show_error_{};
};

}  // namespace fft_visualizer::view

#endif  // FFT_VISUALIZER_FFT_VISUALIZER_VIEW_H
