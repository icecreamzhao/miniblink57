// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/views/examples/label_example.h"

#include "base/macros.h"
#include "base/strings/utf_string_conversions.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/views/background.h"
#include "ui/views/border.h"
#include "ui/views/controls/button/checkbox.h"
#include "ui/views/controls/combobox/combobox.h"
#include "ui/views/controls/label.h"
#include "ui/views/controls/textfield/textfield.h"
#include "ui/views/examples/example_combobox_model.h"
#include "ui/views/layout/box_layout.h"
#include "ui/views/layout/grid_layout.h"
#include "ui/views/view.h"

using base::ASCIIToUTF16;
using base::WideToUTF16;

namespace views {
namespace examples {

    namespace {

        const char* kElideBehaviors[] = { "No Elide", "Truncate", "Elide Head",
            "Elide Middle", "Elide Tail", "Elide Email", "Fade Tail" };
        const char* kAlignments[] = { "Left", "Center", "Right", "Head" };

        // A Label with a clamped preferred width to demonstrate eliding or wrapping.
        class PreferredSizeLabel : public Label {
        public:
            PreferredSizeLabel()
                : Label()
            {
                SetBorder(Border::CreateSolidBorder(1, SK_ColorGRAY));
            }
            ~PreferredSizeLabel() override { }

            // Label:
            gfx::Size GetPreferredSize() const override
            {
                return gfx::Size(50, Label::GetPreferredSize().height());
            }

        private:
            DISALLOW_COPY_AND_ASSIGN(PreferredSizeLabel);
        };

    } // namespace

    LabelExample::LabelExample()
        : ExampleBase("Label")
        , textfield_(NULL)
        , alignment_(NULL)
        , elide_behavior_(NULL)
        , multiline_(NULL)
        , shadows_(NULL)
        , custom_label_(NULL)
    {
    }

    LabelExample::~LabelExample()
    {
        // Remove the views first as some reference combobox models.
        container()->RemoveAllChildViews(true);
    }

    void LabelExample::CreateExampleView(View* container)
    {
        // A very simple label example, followed by additional helpful examples.
        container->SetLayoutManager(new BoxLayout(BoxLayout::kVertical, 0, 0, 10));
        Label* label = new Label(ASCIIToUTF16("Hello world!"));
        container->AddChildView(label);

        const wchar_t hello_world_hebrew[] = L"\x5e9\x5dc\x5d5\x5dd \x5d4\x5e2\x5d5\x5dc\x5dd!";
        label = new Label(WideToUTF16(hello_world_hebrew));
        label->SetHorizontalAlignment(gfx::ALIGN_RIGHT);
        container->AddChildView(label);

        label = new Label(WideToUTF16(L"A UTF16 surrogate pair: \x5d0\x5b0"));
        label->SetHorizontalAlignment(gfx::ALIGN_RIGHT);
        container->AddChildView(label);

        label = new Label(ASCIIToUTF16("A left-aligned blue label."));
        label->SetHorizontalAlignment(gfx::ALIGN_LEFT);
        label->SetEnabledColor(SK_ColorBLUE);
        container->AddChildView(label);

        label = new Label(WideToUTF16(L"Password!"));
        label->SetObscured(true);
        container->AddChildView(label);

        label = new Label(ASCIIToUTF16("A Courier-18 label with shadows."));
        label->SetFontList(gfx::FontList("Courier, 18px"));
        gfx::ShadowValues shadows(1,
            gfx::ShadowValue(gfx::Vector2d(), 1, SK_ColorRED));
        gfx::ShadowValue shadow(gfx::Vector2d(2, 2), 0, SK_ColorGRAY);
        shadows.push_back(shadow);
        label->SetShadows(shadows);
        container->AddChildView(label);

        label = new PreferredSizeLabel();
        label->SetText(ASCIIToUTF16("A long label will elide toward its logical end "
                                    "if the text's width exceeds the label's available width."));
        container->AddChildView(label);

        label = new PreferredSizeLabel();
        label->SetText(ASCIIToUTF16("A multi-line label will wrap onto subsequent "
                                    "lines if the text's width exceeds the label's available width, which is "
                                    "helpful for extemely long text used to demonstrate line wrapping."));
        label->SetMultiLine(true);
        container->AddChildView(label);

        label = new Label(ASCIIToUTF16("Label with thick border"));
        label->SetBorder(Border::CreateSolidBorder(20, SK_ColorRED));
        container->AddChildView(label);

        AddCustomLabel(container);
    }

    void LabelExample::ButtonPressed(Button* button, const ui::Event& event)
    {
        if (button == multiline_) {
            custom_label_->SetMultiLine(multiline_->checked());
        } else if (button == shadows_) {
            gfx::ShadowValues shadows;
            if (shadows_->checked()) {
                shadows.push_back(gfx::ShadowValue(gfx::Vector2d(), 1, SK_ColorRED));
                shadows.push_back(gfx::ShadowValue(gfx::Vector2d(2, 2), 0, SK_ColorGRAY));
            }
            custom_label_->SetShadows(shadows);
        }
        custom_label_->parent()->parent()->Layout();
        custom_label_->SchedulePaint();
    }

    void LabelExample::OnPerformAction(Combobox* combobox)
    {
        if (combobox == alignment_) {
            custom_label_->SetHorizontalAlignment(
                static_cast<gfx::HorizontalAlignment>(combobox->selected_index()));
        } else if (combobox == elide_behavior_) {
            custom_label_->SetElideBehavior(
                static_cast<gfx::ElideBehavior>(combobox->selected_index()));
        }
    }

    void LabelExample::ContentsChanged(Textfield* sender,
        const base::string16& new_contents)
    {
        custom_label_->SetText(new_contents);
        custom_label_->parent()->parent()->Layout();
    }

    void LabelExample::AddCustomLabel(View* container)
    {
        View* control_container = new View();
        control_container->SetBorder(Border::CreateSolidBorder(2, SK_ColorGRAY));
        control_container->set_background(
            Background::CreateSolidBackground(SK_ColorLTGRAY));
        GridLayout* layout = GridLayout::CreatePanel(control_container);
        control_container->SetLayoutManager(layout);

        ColumnSet* column_set = layout->AddColumnSet(0);
        column_set->AddColumn(GridLayout::LEADING, GridLayout::FILL,
            0.0f, GridLayout::USE_PREF, 0, 0);
        column_set->AddColumn(GridLayout::FILL, GridLayout::FILL,
            1.0f, GridLayout::USE_PREF, 0, 0);

        layout->StartRow(0, 0);
        layout->AddView(new Label(ASCIIToUTF16("Content: ")));
        textfield_ = new Textfield();
        textfield_->SetText(ASCIIToUTF16("Use the provided controls to configure the "
                                         "content and presentation of this custom label."));
        textfield_->SetSelectionRange(gfx::Range());
        textfield_->set_controller(this);
        layout->AddView(textfield_);

        alignment_ = AddCombobox(layout, "Alignment: ", kAlignments,
            arraysize(kAlignments));
        elide_behavior_ = AddCombobox(layout, "Elide Behavior: ", kElideBehaviors,
            arraysize(kElideBehaviors));

        column_set = layout->AddColumnSet(1);
        column_set->AddColumn(GridLayout::LEADING, GridLayout::LEADING,
            0, GridLayout::USE_PREF, 0, 0);
        column_set->AddColumn(GridLayout::LEADING, GridLayout::LEADING,
            0, GridLayout::USE_PREF, 0, 0);
        layout->StartRow(0, 1);
        multiline_ = new Checkbox(base::ASCIIToUTF16("Multiline"));
        multiline_->set_listener(this);
        layout->AddView(multiline_);
        shadows_ = new Checkbox(base::ASCIIToUTF16("Shadows"));
        shadows_->set_listener(this);
        layout->AddView(shadows_);
        layout->AddPaddingRow(0, 8);

        column_set = layout->AddColumnSet(2);
        column_set->AddColumn(GridLayout::FILL, GridLayout::FILL,
            1, GridLayout::USE_PREF, 0, 0);
        layout->StartRow(0, 2);
        custom_label_ = new PreferredSizeLabel();
        custom_label_->SetHorizontalAlignment(gfx::ALIGN_LEFT);
        custom_label_->SetElideBehavior(gfx::NO_ELIDE);
        custom_label_->SetText(textfield_->text());
        layout->AddView(custom_label_);

        container->AddChildView(control_container);
    }

    Combobox* LabelExample::AddCombobox(GridLayout* layout,
        const char* name,
        const char** strings,
        int count)
    {
        layout->StartRow(0, 0);
        layout->AddView(new Label(base::ASCIIToUTF16(name)));
        ExampleComboboxModel* model = new ExampleComboboxModel(strings, count);
        example_combobox_models_.push_back(make_scoped_ptr(model));
        Combobox* combobox = new Combobox(model);
        combobox->SetSelectedIndex(0);
        combobox->set_listener(this);
        layout->AddView(combobox);
        return combobox;
    }

} // namespace examples
} // namespace views
