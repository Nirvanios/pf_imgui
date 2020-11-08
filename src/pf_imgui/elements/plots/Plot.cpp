//
// Created by petr on 11/8/20.
//

#include "Plot.h"
#include <algorithm>
#include <implot.h>
#include <utility>

namespace pf::ui::ig {

Plot::Plot(const std::string &elementName, const std::string &caption, const ImVec2 &size,
           std::optional<std::string> xLabel, std::optional<std::string> yLabel)
    : Element(elementName), LabeledElement(elementName, caption),
      ResizableElement(elementName, size), xLabel(std::move(xLabel)), yLabel(std::move(yLabel)) {}

void Plot::renderImpl() {
  if (ImPlot::BeginPlot(getLabel().c_str(), xLabel.has_value() ? xLabel->c_str() : nullptr,
                        yLabel.has_value() ? yLabel->c_str() : nullptr, getSize())) {
    std::ranges::for_each(datas, [](auto &data) { data->render(); });
    ImPlot::EndPlot();
  }
}
}// namespace pf::ui::ig