//
// Created by petr on 10/31/20.
//

#ifndef PF_IMGUI_IMGUI_ELEMENTS_INTERFACE_RESIZABLEELEMENT_H
#define PF_IMGUI_IMGUI_ELEMENTS_INTERFACE_RESIZABLEELEMENT_H

#include "Element.h"
#include <imgui.h>
#include <pf_imgui/_export.h>

namespace pf::ui::ig {
class PF_IMGUI_EXPORT ResizableElement : public virtual Element {
 public:
  ResizableElement(std::string elementName, const ImVec2 &size);

  [[nodiscard]] const ImVec2 &getSize() const;
  void setSize(const ImVec2 &s);

 private:
  ImVec2 size;
};

}// namespace pf::ui::ig
#endif//PF_IMGUI_IMGUI_ELEMENTS_INTERFACE_RESIZABLEELEMENT_H
