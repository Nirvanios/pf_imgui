//
// Created by petr on 10/31/20.
//

#ifndef PF_IMGUI_ELEMENTS_BUTTON_H
#define PF_IMGUI_ELEMENTS_BUTTON_H

#include "interface/Clickable.h"
#include "interface/LabeledElement.h"
#include "interface/ResizableElement.h"
#include <functional>
#include <pf_imgui/_export.h>
#include <string>

namespace pf::ui::ig {

class PF_IMGUI_EXPORT Button : public LabeledElement, public ResizableElement, public Clickable {
 public:
  Button(const std::string &name, std::string caption, ButtonType buttonType = ButtonType::Normal,
         const ImVec2 &size = {0, 0});

  [[nodiscard]] ButtonType getType() const;

  void setType(ButtonType type);

 protected:
  void renderImpl() override;

 private:
  ButtonType type;
};

}// namespace pf::ui::ig
#endif//PF_IMGUI_ELEMENTS_BUTTON_H
