project(fft-visualizer-model)

add_library(${PROJECT_NAME}
        error.h error.cc

        worker/worker.h worker/worker.cc
        worker/cpu_worker.h worker/cpu_worker.cc
        worker/opencl_worker.h worker/opencl_worker.cc

        opencl_model.h opencl_model.cc
        worker_model.h worker_model.cc
        fft_visualizer_model.h fft_visualizer_model.cc

        signal_generator/signal_generator.h signal_generator/signal_generator.cc
        signal_generator/polyharmonic_signal_generator.h signal_generator/polyharmonic_signal_generator.cc
        signal_generator/harmonic_signal_generator.h signal_generator/harmonic_signal_generator.cc)

add_library(fft-visualizer::model
        ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
        PRIVATE ${OpenCL_LIBRARY})

target_include_directories(${PROJECT_NAME}
        PUBLIC . ${OpenCL_INCLUDE_DIR})
