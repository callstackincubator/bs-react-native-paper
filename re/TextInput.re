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
