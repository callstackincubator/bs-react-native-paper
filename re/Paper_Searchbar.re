[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Searchbar";

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  placeholder: string,
  [@bs.optional]
  value: string,
  [@bs.optional] [@bs.as "icon"]
  iconAsString: string,
  [@bs.optional] [@bs.as "icon"]
  iconAsRenderFunc: Icon.renderIcon,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  [@bs.optional]
  style: BsReactNative.Style.t,
  onChangeText: string => unit,
  [@bs.optional]
  onIconPress: BsReactNative.RNEvent.NativeEvent.t => unit,
  [@bs.optional]
  allowFontScaling: bool,
  [@bs.optional]
  autoCorrect: bool,
  [@bs.optional]
  autoFocus: bool,
  [@bs.optional]
  autoCapitalize: Paper_TextInput.capitalize,
  [@bs.optional]
  autoGrow: bool,
  [@bs.optional]
  blurOnSubmit: bool,
  [@bs.optional]
  caretHidden: bool,
  [@bs.optional]
  contextMenuHidden: bool,
  [@bs.optional]
  dataDetectorTypes: string,
  [@bs.optional]
  enablesReturnKeyAutomatically: bool,
  [@bs.optional]
  error: bool,
  [@bs.optional]
  keyboardAppearance: string,
  [@bs.optional]
  defaultValue: string,
  [@bs.optional]
  disabled: bool,
  [@bs.optional]
  disableFullscreenUI: bool,
  [@bs.optional]
  editable: bool,
  [@bs.optional]
  keyboardType: string,
  [@bs.optional]
  inlineImageLeft: string,
  [@bs.optional]
  inlineImagePadding: string,
  [@bs.optional]
  maxHeight: float,
  [@bs.optional]
  maxLength: int,
  [@bs.optional]
  label: string,
  [@bs.optional]
  placeholderTextColor: string,
  [@bs.optional]
  returnKeyType: string,
  [@bs.optional]
  returnKeyLabel: string,
  [@bs.optional]
  spellCheck: bool,
  [@bs.optional]
  textBreakStrategy: string,
  [@bs.optional]
  underlineColorAndroid: string,
  [@bs.optional]
  clearButtonMode: string,
  [@bs.optional]
  clearTextOnFocus: string,
  [@bs.optional]
  secureTextEntry: bool,
  [@bs.optional]
  selectTextOnFocus: bool,
  [@bs.optional]
  selectionColor: string,
  [@bs.optional]
  underlineColor: string,
  [@bs.optional]
  multiline: bool,
  [@bs.optional]
  numberOfLines: int,
  [@bs.optional]
  onChange: unit => unit,
  [@bs.optional]
  onContentSizeChange: unit => unit,
  [@bs.optional]
  onKeyPress: unit => unit,
  [@bs.optional]
  onEndEditing: unit => unit,
  [@bs.optional]
  onLayout: unit => unit,
  [@bs.optional]
  onScroll: unit => unit,
  [@bs.optional]
  onSelectionChange: unit => unit,
  [@bs.optional]
  onSubmitEditing: unit => unit,
  [@bs.optional]
  onFocus: unit => unit,
  [@bs.optional]
  onBlur: unit => unit,
  [@bs.optional]
  testID: string,
};

let make =
    (
      ~placeholder=?,
      ~value=?,
      ~icon=?,
      ~theme=?,
      ~style=?,
      ~onChangeText,
      ~onIconPress=?,
      ~allowFontScaling=false,
      ~autoCorrect=false,
      ~autoFocus=false,
      ~autoCapitalize=?,
      ~autoGrow=false,
      ~blurOnSubmit=false,
      ~caretHidden=false,
      ~contextMenuHidden=false,
      ~dataDetectorTypes=?,
      ~enablesReturnKeyAutomatically=false,
      ~error=false,
      ~keyboardAppearance=?,
      ~defaultValue=?,
      ~disabled=false,
      ~disableFullscreenUI=false,
      ~editable=true,
      ~keyboardType=?,
      ~inlineImageLeft=?,
      ~inlineImagePadding=?,
      ~maxHeight=?,
      ~maxLength=?,
      ~label=?,
      ~placeholderTextColor=?,
      ~returnKeyType=?,
      ~returnKeyLabel=?,
      ~spellCheck=false,
      ~textBreakStrategy=?,
      ~underlineColorAndroid=?,
      ~clearButtonMode=?,
      ~clearTextOnFocus=?,
      ~secureTextEntry=false,
      ~selectTextOnFocus=false,
      ~selectionColor=?,
      ~underlineColor=?,
      ~multiline=false,
      ~numberOfLines=?,
      ~onChange=?,
      ~onContentSizeChange=?,
      ~onKeyPress=?,
      ~onEndEditing=?,
      ~onLayout=?,
      ~onScroll=?,
      ~onSelectionChange=?,
      ~onSubmitEditing=?,
      ~onFocus=?,
      ~onBlur=?,
      ~testID=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      switch (icon) {
      | Some(Icon.Name(name)) =>
        props(
          ~placeholder?,
          ~value?,
          ~iconAsString=name,
          ~theme?,
          ~style?,
          ~onChangeText,
          ~onIconPress?,
          ~allowFontScaling,
          ~autoCorrect,
          ~autoFocus,
          ~autoCapitalize?,
          ~autoGrow,
          ~blurOnSubmit,
          ~caretHidden,
          ~contextMenuHidden,
          ~dataDetectorTypes?,
          ~enablesReturnKeyAutomatically,
          ~error,
          ~keyboardAppearance?,
          ~defaultValue?,
          ~disabled,
          ~disableFullscreenUI,
          ~editable,
          ~keyboardType?,
          ~inlineImageLeft?,
          ~inlineImagePadding?,
          ~maxHeight?,
          ~maxLength?,
          ~label?,
          ~placeholderTextColor?,
          ~returnKeyType?,
          ~returnKeyLabel?,
          ~spellCheck,
          ~textBreakStrategy?,
          ~underlineColorAndroid?,
          ~clearButtonMode?,
          ~clearTextOnFocus?,
          ~secureTextEntry,
          ~selectTextOnFocus,
          ~selectionColor?,
          ~underlineColor?,
          ~multiline,
          ~numberOfLines?,
          ~onChange?,
          ~onContentSizeChange?,
          ~onKeyPress?,
          ~onEndEditing?,
          ~onLayout?,
          ~onScroll?,
          ~onSelectionChange?,
          ~onSubmitEditing?,
          ~onFocus?,
          ~onBlur?,
          ~testID?,
          (),
        )
      | Some(Icon.Element(renderFunc)) =>
        props(
          ~placeholder?,
          ~value?,
          ~iconAsRenderFunc=renderFunc,
          ~theme?,
          ~style?,
          ~onChangeText,
          ~onIconPress?,
          ~allowFontScaling,
          ~autoCorrect,
          ~autoFocus,
          ~autoCapitalize?,
          ~autoGrow,
          ~blurOnSubmit,
          ~caretHidden,
          ~contextMenuHidden,
          ~dataDetectorTypes?,
          ~enablesReturnKeyAutomatically,
          ~error,
          ~keyboardAppearance?,
          ~defaultValue?,
          ~disabled,
          ~disableFullscreenUI,
          ~editable,
          ~keyboardType?,
          ~inlineImageLeft?,
          ~inlineImagePadding?,
          ~maxHeight?,
          ~maxLength?,
          ~label?,
          ~placeholderTextColor?,
          ~returnKeyType?,
          ~returnKeyLabel?,
          ~spellCheck,
          ~textBreakStrategy?,
          ~underlineColorAndroid?,
          ~clearButtonMode?,
          ~clearTextOnFocus?,
          ~secureTextEntry,
          ~selectTextOnFocus,
          ~selectionColor?,
          ~underlineColor?,
          ~multiline,
          ~numberOfLines?,
          ~onChange?,
          ~onContentSizeChange?,
          ~onKeyPress?,
          ~onEndEditing?,
          ~onLayout?,
          ~onScroll?,
          ~onSelectionChange?,
          ~onSubmitEditing?,
          ~onFocus?,
          ~onBlur?,
          ~testID?,
          (),
        )
      | None =>
        props(
          ~placeholder?,
          ~value?,
          ~theme?,
          ~style?,
          ~onChangeText,
          ~onIconPress?,
          ~allowFontScaling,
          ~autoCorrect,
          ~autoFocus,
          ~autoCapitalize?,
          ~autoGrow,
          ~blurOnSubmit,
          ~caretHidden,
          ~contextMenuHidden,
          ~dataDetectorTypes?,
          ~enablesReturnKeyAutomatically,
          ~error,
          ~keyboardAppearance?,
          ~defaultValue?,
          ~disabled,
          ~disableFullscreenUI,
          ~editable,
          ~keyboardType?,
          ~inlineImageLeft?,
          ~inlineImagePadding?,
          ~maxHeight?,
          ~maxLength?,
          ~label?,
          ~placeholderTextColor?,
          ~returnKeyType?,
          ~returnKeyLabel?,
          ~spellCheck,
          ~textBreakStrategy?,
          ~underlineColorAndroid?,
          ~clearButtonMode?,
          ~clearTextOnFocus?,
          ~secureTextEntry,
          ~selectTextOnFocus,
          ~selectionColor?,
          ~underlineColor?,
          ~multiline,
          ~numberOfLines?,
          ~onChange?,
          ~onContentSizeChange?,
          ~onKeyPress?,
          ~onEndEditing?,
          ~onLayout?,
          ~onScroll?,
          ~onSelectionChange?,
          ~onSubmitEditing?,
          ~onFocus?,
          ~onBlur?,
          ~testID?,
          (),
        )
      },
    children,
  );
