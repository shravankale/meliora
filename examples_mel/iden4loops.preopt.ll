; ModuleID = 'iden4loops.ll'
source_filename = "iden4loops.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [15 x i8] c"Array Size: %d\00", align 1
@.str.1 = private unnamed_addr constant [4 x i8] c"%d \00", align 1
@.str.2 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

; Function Attrs: noinline nounwind uwtable
define dso_local void @identity([5 x i32]* noundef %a) #0 !dbg !8 {
entry:
  call void @llvm.dbg.value(metadata [5 x i32]* %a, metadata !17, metadata !DIExpression()), !dbg !18
  call void @llvm.dbg.value(metadata i32 0, metadata !19, metadata !DIExpression()), !dbg !18
  br label %for.cond1.preheader, !dbg !20

for.cond1.preheader:                              ; preds = %entry, %for.inc6
  %indvars.iv12 = phi i64 [ 0, %entry ], [ %indvars.iv.next13, %for.inc6 ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv12, metadata !19, metadata !DIExpression()), !dbg !18
  call void @llvm.dbg.value(metadata i32 0, metadata !22, metadata !DIExpression()), !dbg !18
  br label %for.body3, !dbg !23

for.cond9.preheader:                              ; preds = %for.inc6
  call void @llvm.dbg.value(metadata i32 0, metadata !27, metadata !DIExpression()), !dbg !18
  br label %for.cond12.preheader, !dbg !28

for.body3:                                        ; preds = %for.cond1.preheader, %for.body3
  %indvars.iv9 = phi i64 [ 0, %for.cond1.preheader ], [ %indvars.iv.next10, %for.body3 ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv9, metadata !22, metadata !DIExpression()), !dbg !18
  %arrayidx5 = getelementptr inbounds [5 x i32], [5 x i32]* %a, i64 %indvars.iv12, i64 %indvars.iv9, !dbg !30
  store i32 0, i32* %arrayidx5, align 4, !dbg !33
  %indvars.iv.next10 = add nuw nsw i64 %indvars.iv9, 1, !dbg !34
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next10, metadata !22, metadata !DIExpression()), !dbg !18
  %exitcond11 = icmp ne i64 %indvars.iv.next10, 5, !dbg !35
  br i1 %exitcond11, label %for.body3, label %for.inc6, !dbg !23, !llvm.loop !36

for.inc6:                                         ; preds = %for.body3
  %indvars.iv.next13 = add nuw nsw i64 %indvars.iv12, 1, !dbg !39
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next13, metadata !19, metadata !DIExpression()), !dbg !18
  %exitcond14 = icmp ne i64 %indvars.iv.next13, 5, !dbg !40
  br i1 %exitcond14, label %for.cond1.preheader, label %for.cond9.preheader, !dbg !20, !llvm.loop !41

for.cond12.preheader:                             ; preds = %for.cond9.preheader, %for.inc23
  %indvars.iv6 = phi i64 [ 0, %for.cond9.preheader ], [ %indvars.iv.next7, %for.inc23 ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv6, metadata !27, metadata !DIExpression()), !dbg !18
  call void @llvm.dbg.value(metadata i32 0, metadata !43, metadata !DIExpression()), !dbg !18
  br label %for.body14, !dbg !44

for.body14:                                       ; preds = %for.cond12.preheader, %for.inc20
  %indvars.iv = phi i64 [ 0, %for.cond12.preheader ], [ %indvars.iv.next, %for.inc20 ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv, metadata !43, metadata !DIExpression()), !dbg !18
  %cmp15 = icmp eq i64 %indvars.iv6, %indvars.iv, !dbg !48
  br i1 %cmp15, label %if.then, label %for.inc20, !dbg !52

if.then:                                          ; preds = %for.body14
  %arrayidx19 = getelementptr inbounds [5 x i32], [5 x i32]* %a, i64 %indvars.iv, i64 %indvars.iv, !dbg !53
  store i32 1, i32* %arrayidx19, align 4, !dbg !55
  br label %for.inc20, !dbg !56

for.inc20:                                        ; preds = %for.body14, %if.then
  %indvars.iv.next = add nuw nsw i64 %indvars.iv, 1, !dbg !57
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next, metadata !43, metadata !DIExpression()), !dbg !18
  %exitcond = icmp ne i64 %indvars.iv.next, 5, !dbg !58
  br i1 %exitcond, label %for.body14, label %for.inc23, !dbg !44, !llvm.loop !59

for.inc23:                                        ; preds = %for.inc20
  %indvars.iv.next7 = add nuw nsw i64 %indvars.iv6, 1, !dbg !61
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next7, metadata !27, metadata !DIExpression()), !dbg !18
  %exitcond8 = icmp ne i64 %indvars.iv.next7, 5, !dbg !62
  br i1 %exitcond8, label %for.cond12.preheader, label %for.end25, !dbg !28, !llvm.loop !63

for.end25:                                        ; preds = %for.inc23
  ret void, !dbg !65
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @main() #0 !dbg !66 {
entry:
  %a = alloca [5 x [5 x i32]], align 16
  call void @llvm.dbg.declare(metadata [5 x [5 x i32]]* %a, metadata !69, metadata !DIExpression()), !dbg !72
  %arraydecay = getelementptr inbounds [5 x [5 x i32]], [5 x [5 x i32]]* %a, i64 0, i64 0, !dbg !73
  call void @identity([5 x i32]* noundef nonnull %arraydecay), !dbg !74
  call void @llvm.dbg.value(metadata i32 25, metadata !75, metadata !DIExpression()), !dbg !76
  %call = call i32 (i8*, ...) @printf(i8* noundef nonnull dereferenceable(1) getelementptr inbounds ([15 x i8], [15 x i8]* @.str, i64 0, i64 0), i32 noundef 25) #4, !dbg !77
  call void @llvm.dbg.value(metadata i32 0, metadata !78, metadata !DIExpression()), !dbg !80
  br label %for.cond1.preheader, !dbg !81

for.cond1.preheader:                              ; preds = %entry, %for.end
  %indvars.iv3 = phi i64 [ 0, %entry ], [ %indvars.iv.next4, %for.end ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv3, metadata !78, metadata !DIExpression()), !dbg !80
  call void @llvm.dbg.value(metadata i32 0, metadata !82, metadata !DIExpression()), !dbg !86
  br label %for.body3, !dbg !87

for.body3:                                        ; preds = %for.cond1.preheader, %for.body3
  %indvars.iv = phi i64 [ 0, %for.cond1.preheader ], [ %indvars.iv.next, %for.body3 ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv, metadata !82, metadata !DIExpression()), !dbg !86
  %arrayidx5 = getelementptr inbounds [5 x [5 x i32]], [5 x [5 x i32]]* %a, i64 0, i64 %indvars.iv3, i64 %indvars.iv, !dbg !88
  %0 = load i32, i32* %arrayidx5, align 4, !dbg !88
  %call6 = call i32 (i8*, ...) @printf(i8* noundef nonnull dereferenceable(1) getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 noundef %0) #4, !dbg !91
  %indvars.iv.next = add nuw nsw i64 %indvars.iv, 1, !dbg !92
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next, metadata !82, metadata !DIExpression()), !dbg !86
  %exitcond = icmp ne i64 %indvars.iv.next, 5, !dbg !93
  br i1 %exitcond, label %for.body3, label %for.end, !dbg !87, !llvm.loop !94

for.end:                                          ; preds = %for.body3
  %putchar = call i32 @putchar(i32 10), !dbg !96
  %indvars.iv.next4 = add nuw nsw i64 %indvars.iv3, 1, !dbg !97
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next4, metadata !78, metadata !DIExpression()), !dbg !80
  %exitcond5 = icmp ne i64 %indvars.iv.next4, 5, !dbg !98
  br i1 %exitcond5, label %for.cond1.preheader, label %for.end10, !dbg !81, !llvm.loop !99

for.end10:                                        ; preds = %for.end
  ret i32 0, !dbg !101
}

declare dso_local i32 @printf(i8* noundef, ...) #2

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.value(metadata, metadata, metadata) #1

; Function Attrs: nofree nounwind
declare noundef i32 @putchar(i32 noundef) #3

attributes #0 = { noinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { nofree nounwind }
attributes #4 = { nounwind }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6}
!llvm.ident = !{!7}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 14.0.1 (https://github.com/llvm/llvm-project.git c62053979489ccb002efe411c3af059addcb5d7d)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "iden4loops.c", directory: "/home/users/shravank/projects/meliora2/Meliora/examples_mel", checksumkind: CSK_MD5, checksum: "aef025a3bc9fe508cb64432ad9eaeaca")
!2 = !{i32 7, !"Dwarf Version", i32 5}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{i32 7, !"uwtable", i32 1}
!6 = !{i32 7, !"frame-pointer", i32 2}
!7 = !{!"clang version 14.0.1 (https://github.com/llvm/llvm-project.git c62053979489ccb002efe411c3af059addcb5d7d)"}
!8 = distinct !DISubprogram(name: "identity", scope: !1, file: !1, line: 7, type: !9, scopeLine: 7, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !16)
!9 = !DISubroutineType(types: !10)
!10 = !{null, !11}
!11 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !12, size: 64)
!12 = !DICompositeType(tag: DW_TAG_array_type, baseType: !13, size: 160, elements: !14)
!13 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!14 = !{!15}
!15 = !DISubrange(count: 5)
!16 = !{}
!17 = !DILocalVariable(name: "a", arg: 1, scope: !8, file: !1, line: 7, type: !11)
!18 = !DILocation(line: 0, scope: !8)
!19 = !DILocalVariable(name: "loop_i", scope: !8, file: !1, line: 9, type: !13)
!20 = !DILocation(line: 11, column: 5, scope: !21)
!21 = distinct !DILexicalBlock(scope: !8, file: !1, line: 11, column: 5)
!22 = !DILocalVariable(name: "loop_j", scope: !8, file: !1, line: 9, type: !13)
!23 = !DILocation(line: 12, column: 9, scope: !24)
!24 = distinct !DILexicalBlock(scope: !25, file: !1, line: 12, column: 9)
!25 = distinct !DILexicalBlock(scope: !26, file: !1, line: 11, column: 38)
!26 = distinct !DILexicalBlock(scope: !21, file: !1, line: 11, column: 5)
!27 = !DILocalVariable(name: "loop_k", scope: !8, file: !1, line: 9, type: !13)
!28 = !DILocation(line: 17, column: 5, scope: !29)
!29 = distinct !DILexicalBlock(scope: !8, file: !1, line: 17, column: 5)
!30 = !DILocation(line: 13, column: 13, scope: !31)
!31 = distinct !DILexicalBlock(scope: !32, file: !1, line: 12, column: 42)
!32 = distinct !DILexicalBlock(scope: !24, file: !1, line: 12, column: 9)
!33 = !DILocation(line: 13, column: 30, scope: !31)
!34 = !DILocation(line: 12, column: 39, scope: !32)
!35 = !DILocation(line: 12, column: 29, scope: !32)
!36 = distinct !{!36, !23, !37, !38}
!37 = !DILocation(line: 14, column: 9, scope: !24)
!38 = !{!"llvm.loop.mustprogress"}
!39 = !DILocation(line: 11, column: 35, scope: !26)
!40 = !DILocation(line: 11, column: 25, scope: !26)
!41 = distinct !{!41, !20, !42, !38}
!42 = !DILocation(line: 15, column: 5, scope: !21)
!43 = !DILocalVariable(name: "loop_l", scope: !8, file: !1, line: 9, type: !13)
!44 = !DILocation(line: 18, column: 9, scope: !45)
!45 = distinct !DILexicalBlock(scope: !46, file: !1, line: 18, column: 9)
!46 = distinct !DILexicalBlock(scope: !47, file: !1, line: 17, column: 38)
!47 = distinct !DILexicalBlock(scope: !29, file: !1, line: 17, column: 5)
!48 = !DILocation(line: 19, column: 22, scope: !49)
!49 = distinct !DILexicalBlock(scope: !50, file: !1, line: 19, column: 16)
!50 = distinct !DILexicalBlock(scope: !51, file: !1, line: 18, column: 42)
!51 = distinct !DILexicalBlock(scope: !45, file: !1, line: 18, column: 9)
!52 = !DILocation(line: 19, column: 16, scope: !50)
!53 = !DILocation(line: 20, column: 17, scope: !54)
!54 = distinct !DILexicalBlock(scope: !49, file: !1, line: 19, column: 31)
!55 = !DILocation(line: 20, column: 34, scope: !54)
!56 = !DILocation(line: 21, column: 13, scope: !54)
!57 = !DILocation(line: 18, column: 39, scope: !51)
!58 = !DILocation(line: 18, column: 29, scope: !51)
!59 = distinct !{!59, !44, !60, !38}
!60 = !DILocation(line: 22, column: 9, scope: !45)
!61 = !DILocation(line: 17, column: 35, scope: !47)
!62 = !DILocation(line: 17, column: 25, scope: !47)
!63 = distinct !{!63, !28, !64, !38}
!64 = !DILocation(line: 23, column: 5, scope: !29)
!65 = !DILocation(line: 24, column: 1, scope: !8)
!66 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 26, type: !67, scopeLine: 26, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !16)
!67 = !DISubroutineType(types: !68)
!68 = !{!13}
!69 = !DILocalVariable(name: "a", scope: !66, file: !1, line: 29, type: !70)
!70 = !DICompositeType(tag: DW_TAG_array_type, baseType: !13, size: 800, elements: !71)
!71 = !{!15, !15}
!72 = !DILocation(line: 29, column: 9, scope: !66)
!73 = !DILocation(line: 31, column: 14, scope: !66)
!74 = !DILocation(line: 31, column: 5, scope: !66)
!75 = !DILocalVariable(name: "a_size", scope: !66, file: !1, line: 33, type: !13)
!76 = !DILocation(line: 0, scope: !66)
!77 = !DILocation(line: 34, column: 5, scope: !66)
!78 = !DILocalVariable(name: "i", scope: !79, file: !1, line: 37, type: !13)
!79 = distinct !DILexicalBlock(scope: !66, file: !1, line: 37, column: 5)
!80 = !DILocation(line: 0, scope: !79)
!81 = !DILocation(line: 37, column: 5, scope: !79)
!82 = !DILocalVariable(name: "j", scope: !83, file: !1, line: 38, type: !13)
!83 = distinct !DILexicalBlock(scope: !84, file: !1, line: 38, column: 9)
!84 = distinct !DILexicalBlock(scope: !85, file: !1, line: 37, column: 33)
!85 = distinct !DILexicalBlock(scope: !79, file: !1, line: 37, column: 5)
!86 = !DILocation(line: 0, scope: !83)
!87 = !DILocation(line: 38, column: 9, scope: !83)
!88 = !DILocation(line: 39, column: 27, scope: !89)
!89 = distinct !DILexicalBlock(scope: !90, file: !1, line: 38, column: 37)
!90 = distinct !DILexicalBlock(scope: !83, file: !1, line: 38, column: 9)
!91 = !DILocation(line: 39, column: 13, scope: !89)
!92 = !DILocation(line: 38, column: 33, scope: !90)
!93 = !DILocation(line: 38, column: 27, scope: !90)
!94 = distinct !{!94, !87, !95, !38}
!95 = !DILocation(line: 40, column: 9, scope: !83)
!96 = !DILocation(line: 41, column: 9, scope: !84)
!97 = !DILocation(line: 37, column: 29, scope: !85)
!98 = !DILocation(line: 37, column: 23, scope: !85)
!99 = distinct !{!99, !81, !100, !38}
!100 = !DILocation(line: 42, column: 5, scope: !79)
!101 = !DILocation(line: 44, column: 5, scope: !66)
