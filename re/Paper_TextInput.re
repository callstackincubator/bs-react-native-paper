[@bs.deriving jsConverter]
type capitalize = [ | `none | `sentences | `words | `characters];

[@bs.deriving jsConverter]
type modes = [ | [@bs.as "flat"] `flat | [@bs.as "outlined"] `outlined];

[@bs.module "react-native-paper"] [@react.component]
external make:
  (
    ~mode: modes=?,
    ~allowFontScaling: bool=?,
    ~autoCorrect: bool=?,
    ~autoFocus: bool=?,
    ~autoGrow: bool=?,
    ~blurOnSubmit: bool=?,
    ~caretHidden: bool=?,
    ~contextMenuHidden: bool=?,
    ~dataDetectorTypes: string=?,
    ~enablesReturnKeyAutomatically: bool=?,
    ~error: bool=?,
    ~keyboardAppearance: string=?,
    ~defaultValue: string=?,
    ~disabled: bool=?,
    ~disableFullscreenUI: bool=?,
    ~editable: bool=?,
    ~keyboardType: string=?,
    ~inlineImageLeft: string=?,
    ~inlineImagePadding: string=?,
    ~maxHeight: float=?,
    ~maxLength: int=?,
    ~label: string=?,
    ~placeholder: string=?,
    ~placeholderTextColor: string=?,
    ~returnKeyType: string=?,
    ~returnKeyLabel: string=?,
    ~spellCheck: bool=?,
    ~textBreakStrategy: string=?,
    ~underlineColorAndroid: string=?,
    ~clearButtonMode: string=?,
    ~clearTextOnFocus: string=?,
    ~secureTextEntry: bool=?,
    ~selectTextOnFocus: bool=?,
    ~selection: Js.t({..})=?,
    ~selectionColor: string=?,
    ~underlineColor: string=?,
    ~multiline: bool=?,
    ~numberOfLines: int=?,
    ~value: string=?,
    ~theme: Paper_ThemeProvider.appTheme=?,
    ~style: ReactNative.Style.t=?,
    ~onChange: unit => unit=?,
    ~onChangeText: string => unit=?,
    ~onContentSizeChange: unit => unit=?,
    ~onKeyPress: unit => unit=?,
    ~onEndEditing: unit => unit=?,
    ~onLayout: unit => unit=?,
    ~onScroll: unit => unit=?,
    ~onSelectionChange: unit => unit=?,
    ~onSubmitEditing: unit => unit=?,
    ~onFocus: unit => unit=?,
    ~onBlur: unit => unit=?,
    ~testID: string=?,
    ~autoCapitalize: string=?,
    ~children: React.element=?
  ) =>
  React.element =
  "TextInput";

let makeProps = (~autoCapitalize=?) =>
  makeProps(
    ~autoCapitalize=?Belt.Option.map(autoCapitalize, capitalizeToJs),
  );
