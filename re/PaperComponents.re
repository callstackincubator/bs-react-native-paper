type jsUnsafe;

external toJsUnsafe : 'a => jsUnsafe = "%identity";

let wrap_bool = (b: option(bool)) =>
  switch b {
  | Some(value) => Js.Nullable.return(Js.Boolean.to_js_boolean(value))
  | None => Js.Nullable.undefined
  };

let unwrap_value =
    (
      r: [<
        | `Int(int)
        | `IntArray(array(int))
        | `String(string)
        | `StringArray(array(string))
        | `Float(float)
        | `FloatArray(array(float))
        | `Date(Js.Date.t)
        | `ReactElement(ReasonReact.reactElement)
        | `Object(Js.t({..}))
      ]
    ) =>
  switch r {
  | `String(s) => toJsUnsafe(s)
  | `Int(i) => toJsUnsafe(i)
  | `StringArray(a) => toJsUnsafe(a)
  | `IntArray(a) => toJsUnsafe(a)
  | `Float(f) => toJsUnsafe(f)
  | `FloatArray(a) => toJsUnsafe(a)
  | `Date(d) => toJsUnsafe(d)
  | `ReactElement(e) => toJsUnsafe(e)
  | `Object(o) => toJsUnsafe(o)
  };

let option_map = (fn, option) =>
  switch option {
  | Some(value) => Some(fn(value))
  | None => None
  };

module Caption = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "Caption";

  let make =
    (
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": from_opt(style)
        }
      ),
    children
  );
};

module Card = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "Card";

  let make =
    (
      ~elevation: option(int)=?,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": from_opt(style),
          "elevation": from_opt(elevation),
          "theme": from_opt(theme),
          "onPress": from_opt(onPress)
        }
      ),
    children
  );
};

module CardActions = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "CardActions";

  let make =
    (
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": from_opt(style)
        }
      ),
    children
  );
};

module CardContent = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "CardContent";

  let make =
    (
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": from_opt(style)
        }
      ),
    children
  );
};

module CardCover = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "CardCover";

  let make =
    (
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": from_opt(style),
          "theme": from_opt(theme)
        }
      ),
    children
  );
};

module Checkbox = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "Checkbox";

  let make =
    (
      ~checked: option(bool),
      ~theme: option(Js.t({..}))=?,
      ~disabled: option(bool)=?,
      ~color: option(string)=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": from_opt(style),
          "checked": from_opt(checked),
          "theme": from_opt(theme),
          "onPress": from_opt(onPress),
          "color": from_opt(color),
          "disabled": from_opt(disabled)
        }
      ),
    children
  );
};

module Dialog = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "Dialog";

  let make =
    (
      ~dismissable: option(bool)=?,
      ~visible: option(bool),
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onDismiss: option(unit => unit),
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "dismissable": from_opt(dismissable),
          "visible": from_opt(visible),
          "style": from_opt(style),
          "theme": from_opt(theme),
          "onDismiss": from_opt(onDismiss)
        }
      ),
    children
  );
};

module DialogActions = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "DialogActions";

  let make =
    (
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": from_opt(style)
        }
      ),
    children
  );
};

module DialogContent = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "DialogContent";

  let make =
    (
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": from_opt(style)
        }
      ),
    children
  );
};

module DialogScrollArea = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "DialogScrollArea";

  let make =
    (
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": from_opt(style)
        }
      ),
    children
  );
};

module DialogTitle = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "DialogTitle";

  let make =
    (
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": from_opt(style),
          "theme": from_opt(theme)
        }
      ),
    children
  );
};

module Divider = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "Divider";

  let make =
    (
      ~inset: option(bool)=?,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "inset": from_opt(inset),
          "style": from_opt(style),
          "theme": from_opt(theme)
        }
      ),
    children
  );
};

module DrawerItem = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "DrawerItem";

  let make =
    (
      ~label: option(string),
      ~icon: option(ReasonReact.reactElement)=?,
      ~active: option(bool)=?,
      ~theme: option(Js.t({..}))=?,
      ~color: option(string)=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "label": from_opt(label),
          "icon": from_opt(icon),
          "active": from_opt(active),
          "color": from_opt(color),
          "onPress": from_opt(onPress),
          "theme": from_opt(theme)
        }
      ),
    children
  );
};

module DrawerSection = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "DrawerSection";

  let make =
    (
      ~title: option(string)=?,
      ~theme: option(Js.t({..}))=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "title": from_opt(title),
          "theme": from_opt(theme)
        }
      ),
    children
  );
};

module FAB = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "FAB";

  let make =
    (
      ~small: option(bool)=?,
      ~dark: option(bool)=?,
      ~color: option(string)=?,
      ~theme: option(Js.t({..}))=?,
      ~icon: option(ReasonReact.reactElement),
      ~style: option(BsReactNative.Style.t)=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "small": from_opt(small),
          "dark": from_opt(dark),
          "color": from_opt(color),
          "icon": from_opt(icon),
          "onPress": from_opt(onPress),
          "style": from_opt(style),
          "theme": from_opt(theme)
        }
      ),
    children
  );
};

module Headline = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "Headline";

  let make =
    (
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": from_opt(style)
        }
      ),
    children
  );
};

module Modal = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "Modal";

  let make =
    (
      ~dismissable: option(bool)=?,
      ~visible: option(bool),
      ~onDismiss: option(unit => unit),
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "dismissable": from_opt(dismissable),
          "visible": from_opt(visible),
          "onDismiss": from_opt(onDismiss)
        }
      ),
    children
  );
};

module Paper = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "Paper";

  let make =
    (
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": from_opt(style),
          "theme": from_opt(theme)
        }
      ),
    children
  );
};

module Paragraph = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "Paragraph";

  let make =
    (
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": from_opt(style)
        }
      ),
    children
  );
};

module ProgressBar = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "ProgressBar";

  let make =
    (
      ~progress: option(float),
      ~color: option(string)=?,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "progress": from_opt(progress),
          "color": from_opt(color),
          "theme": from_opt(theme),
          "style": from_opt(style)
        }
      ),
    children
  );
};

module RadioButton = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "RadioButton";

  let make =
    (
      ~checked: option(bool),
      ~disabled: option(bool)=?,
      ~color: option(string)=?,
      ~theme: option(Js.t({..}))=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "checked": from_opt(checked),
          "disabled": from_opt(disabled),
          "onPress": from_opt(onPress),
          "color": from_opt(color),
          "theme": from_opt(theme)
        }
      ),
    children
  );
};

module SearchBar = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "SearchBar";

  let make =
    (
      ~placeholder: option(string)=?,
      ~value: option(string),
      ~icon: option(ReasonReact.reactElement)=?,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onChangeText: option(string => unit),
      ~onIconPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "placeholder": from_opt(placeholder),
          "value": from_opt(value),
          "icon": from_opt(icon),
          "onChangeText": from_opt(onChangeText),
          "onIconPress": from_opt(onIconPress),
          "theme": from_opt(theme),
          "style": from_opt(style)
        }
      ),
    children
  );
};

module Subheading = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "Subheading";

  let make =
    (
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": from_opt(style)
        }
      ),
    children
  );
};

module Switch = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "Switch";

  let make =
    (
      ~disabled: option(bool)=?,
      ~value: option(bool)=?,
      ~color: option(string)=?,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onValueChange: option(bool => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "disabled": from_opt(disabled),
          "value": from_opt(value),
          "color": from_opt(color),
          "onValueChange": from_opt(onValueChange),
          "theme": from_opt(theme),
          "style": from_opt(style)
        }
      ),
    children
  );
};

module Text = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "Text";

  let make =
    (
      ~selectable: option(bool)=?,
      ~acessible: option(bool)=?,
      ~elipsizeMode: option(string)=?,
      ~nativeID: option(string)=?,
      ~numberOfLines: option(int)=?,
      ~pressRetentionOffset: option(Js.t({..}))=?,
      ~allowFontScaling: option(bool)=?,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onLayout: option(unit => unit)=?,
      ~onLongPress: option(unit => unit)=?,
      ~onPress: option(unit => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "selectable": from_opt(selectable),
          "acessible": from_opt(acessible),
          "elipsizeMode": from_opt(elipsizeMode),
          "nativeID": from_opt(nativeID),
          "numberOfLines": from_opt(numberOfLines),
          "pressRetentionOffset": from_opt(pressRetentionOffset),
          "allowFontScaling": from_opt(allowFontScaling),
          "onLayout": from_opt(onLayout),
          "onLongPress": from_opt(onLongPress),
          "onPress": from_opt(onPress),
          "theme": from_opt(theme),
          "style": from_opt(style)
        }
      ),
    children
  );
};

module TextInput = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "TextInput";

  let make =
    (
      ~allowFontScaling: option(bool)=?,
      ~autoCorrect: option(bool)=?,
      ~autoFocus: option(bool)=?,
      ~autoCapitalize: option(bool)=?,
      ~autoGrow: option(bool)=?,
      ~blurOnSubmit: option(bool)=?,
      ~caretHidden: option(bool)=?,
      ~contextMenuHidden: option(bool)=?,
      ~dataDetectorTypes: option(string)=?,
      ~enablesReturnKeyAutomatically: option(bool)=?,
      ~keyboardAppearance: option(string)=?,
      ~defaultValue: option(string)=?,
      ~disabled: option(bool)=?,
      ~disableFullscreenUI: option(bool)=?,
      ~editable: option(bool)=?,
      ~keyboardType: option(string)=?,
      ~inlineImageLeft: option(string)=?,
      ~inlineImagePadding: option(string)=?,
      ~maxHeight: option(float)=?,
      ~maxLength: option(int)=?,
      ~label: option(string)=?,
      ~placeholder: option(string)=?,
      ~placeholderTextColor: option(string)=?,
      ~returnKeyType: option(string)=?,
      ~returnKeyLabel: option(string)=?,
      ~spellCheck: option(bool)=?,
      ~textBreakStrategy: option(string)=?,
      ~underlineColorAndroid: option(string)=?,
      ~clearButtonMode: option(string)=?,
      ~clearTextOnFocus: option(string)=?,
      ~secureTextEntry: option(bool)=?,
      ~selectTextOnFocus: option(bool)=?,
      ~selection: option(Js.t({..}))=?,
      ~selectionColor: option(string)=?,
      ~underlineColor: option(string)=?,
      ~multline: option(bool),
      ~numberOfLines: option(int),
      ~value: option(string)=?,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onChange: option(unit => unit)=?,
      ~onChangeText: option(string => unit)=?,
      ~onContentSizeChange: option(unit => unit)=?,
      ~onKeyPress: option(unit => unit)=?,
      ~onEndEditing: option(unit => unit)=?,
      ~onLayout: option(unit => unit)=?,
      ~onScroll: option(unit => unit)=?,
      ~onSelectionChange: option(unit => unit)=?,
      ~onSubmitEditing: option(unit => unit)=?,
      ~onFocus: option(unit => unit)=?,
      ~onBlur: option(unit => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "allowFontScaling": from_opt(allowFontScaling),
          "autoCorrect": from_opt(autoCorrect),
          "autoFocus": from_opt(autoFocus),
          "autoCapitalize": from_opt(autoCapitalize),
          "autoGrow": from_opt(autoGrow),
          "blurOnSubmit": from_opt(blurOnSubmit),
          "caretHidden": from_opt(caretHidden),
          "contextMenuHidden": from_opt(contextMenuHidden),
          "dataDetectorTypes": from_opt(dataDetectorTypes),
          "enablesReturnKeyAutomatically": from_opt(enablesReturnKeyAutomatically),
          "keyboardAppearance": from_opt(keyboardAppearance),
          "defaultValue": from_opt(defaultValue),
          "disabled": from_opt(disabled),
          "disableFullscreenUI": from_opt(disableFullscreenUI),
          "editable": from_opt(editable),
          "keyboardType": from_opt(keyboardType),
          "inlineImageLeft": from_opt(inlineImageLeft),
          "inlineImagePadding": from_opt(inlineImagePadding),
          "maxHeight": from_opt(maxHeight),
          "maxLength": from_opt(maxLength),
          "label": from_opt(label),
          "placeholder": from_opt(placeholder),
          "placeholderTextColor": from_opt(placeholderTextColor),
          "returnKeyType": from_opt(returnKeyType),
          "returnKeyLabel": from_opt(returnKeyLabel),
          "spellCheck": from_opt(spellCheck),
          "textBreakStrategy": from_opt(textBreakStrategy),
          "underlineColorAndroid": from_opt(underlineColorAndroid),
          "clearButtonMode": from_opt(clearButtonMode),
          "clearTextOnFocus": from_opt(clearTextOnFocus),
          "secureTextEntry": from_opt(secureTextEntry),
          "selectTextOnFocus": from_opt(selectTextOnFocus),
          "selection": from_opt(selection),
          "selectionColor": from_opt(selectionColor),
          "underlineColor": from_opt(underlineColor),
          "multline": from_opt(multline),
          "numberOfLines": from_opt(numberOfLines),
          "value": from_opt(value),
          "theme": from_opt(theme),
          "style": from_opt(style),
          "onChange": from_opt(onChange),
          "onChangeText": from_opt(onChangeText),
          "onContentSizeChange": from_opt(onContentSizeChange),
          "onKeyPress": from_opt(onKeyPress),
          "onEndEditing": from_opt(onEndEditing),
          "onLayout": from_opt(onLayout),
          "onScroll": from_opt(onScroll),
          "onSelectionChange": from_opt(onSelectionChange),
          "onSubmitEditing": from_opt(onSubmitEditing),
          "onFocus": from_opt(onFocus),
          "onBlur": from_opt(onBlur)
        }
      ),
    children
  );
};

module Title = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "Title";

  let make =
    (
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": from_opt(style)
        }
      ),
    children
  );
};

module Toolbar = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "Toolbar";

  let make =
    (
      ~dark: option(bool)=?,
      ~statusBarHeight: option(float)=?,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "dark": from_opt(dark),
          "statusBarHeight": from_opt(statusBarHeight),
          "theme": from_opt(theme),
          "style": from_opt(style)
        }
      ),
    children
  );
};

module ToolbarAction = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "ToolbarAction";

  let make =
    (
      ~dark: option(bool)=?,
      ~size: option(float)=?,
      ~icon: option(ReasonReact.reactElement),
      ~style: option(BsReactNative.Style.t)=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "dark": from_opt(dark),
          "size": from_opt(size),
          "icon": from_opt(icon),
          "onPress": from_opt(onPress),
          "style": from_opt(style)
        }
      ),
    children
  );
};

module ToolbarBackAction = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "ToolbarBackAction";

  let make =
    (
      ~dark: option(bool)=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "dark": from_opt(dark),
          "onPress": from_opt(onPress),
          "style": from_opt(style)
        }
      ),
    children
  );
};

module ToolbarContent = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "ToolbarContent";

  let make =
    (
      ~dark: option(bool)=?,
      ~title: option(string),
      ~titleStyle: option(Js.t({..}))=?,
      ~subtitle: option(string)=?,
      ~subtitleStyle: option(Js.t({..}))=?,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "dark": from_opt(dark),
          "onPress": from_opt(onPress),
          "title": from_opt(title),
          "titleStyle": from_opt(titleStyle),
          "subtitle": from_opt(subtitle),
          "subtitleStyle": from_opt(subtitleStyle),
          "style": from_opt(style),
          "theme": from_opt(theme)
        }
      ),
    children
  );
};

module TouchableRipple = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "TouchableRipple";

  let make =
    (
      ~borderless: option(bool)=?,
      ~background: option(Js.t({..}))=?,
      ~disabled: option(bool)=?,
      ~rippleColor: option(string)=?,
      ~underlayColor: option(string)=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~theme: option(Js.t({..}))=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "borderless": from_opt(borderless),
          "background": from_opt(background),
          "disabled": from_opt(disabled),
          "rippleColor": from_opt(rippleColor),
          "underlayColor": from_opt(underlayColor),
          "theme": from_opt(theme),
          "onPress": from_opt(onPress),
          "style": from_opt(style)
        }
      ),
    children
  );
};